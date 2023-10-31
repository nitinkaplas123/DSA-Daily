Solution 1-:
Steps-:
1)Just go from i=n/2 to n
2)where x=i and y=reverse(x)
3)Now check if x+y==n if yes then return 1 else return false.

Test case-> 
n=181
o/p ->true   x=140 and rev=041 

Suppose we run from i=0;i<=num/2
i=40 , rev=04 

if we run from i=num/2;i<=num.
i=140, rev=041
num=140+041
num=>181.


This is the case we go num/2 to num not 0 to num/2.

Why we run the loop half -:
1)suppose we run full loop from 0 to num 
  where n=180 suppose

  x=i;
  y=rev(i);

  x=0,y=0,
  1)
  x=19,y=91
  x=91,y=19
  so here duplicate came thats why we skip half of it.




Code-:Time->O(N)
bool sumOfNumberAndReverse(int num) 
{
        for(int i=num/2;i<=num;i++)
        {
            int x=i;
            string str=to_string(i);
            reverse(str.begin(),str.end());

            if(x+stoi(str)==num) return 1;
        }
        return 0;
}