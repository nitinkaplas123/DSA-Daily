Solution 1-:

Steps-:
1)Here b is our carry  (using & opeartor)
  at every step if we have encounter with 2 1s then we have a carry at next step.
2)A is our answer using xor opeartor 

Code-: Time->O(max(a,b)no. of bits)
int getSum(int a, int b) 
{
        while(b!=0)
        {
            int carry=((a&b)<<1);
            a=a^b;
            b=carry;
        }
        return a;
}