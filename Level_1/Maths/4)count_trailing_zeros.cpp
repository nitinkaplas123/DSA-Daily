Explanation -:Notebook ->15   Page->21

Question-> Given number n we have to find the trailing zeros of factorial of given number.

Eg.-> 5 
Its factorial is ->120

Now count the zeros from end its count -> 1 

O/p -> 1 

Solution 1-:
Steps-:
1)First find factorial then count the zeros from the end.

Code-:
int trailingZeroes(int n) {
        long long ans=1;
        for(int i=2;i<=n;i++)
        {
            ans=ans*i;
        }
        

        int count=0;
        while(ans!=0)
        {
           int rem=ans%10;
           if(rem==0)
           count++;
           else
           break;
           ans=ans/10;
        }
        return count;
    }



Solution 2-:
Steps-:
1)Here we have to count trailing zeros of factorial of a number.
2)Zeros  at the end will make through 5*2=>10 
3)So we have to count the pairs of 5,2 which makes 10.
4)As 2s count is very much so we only count 5.

Eg. N=25
1,2,3,....5,6,    ....10,11,12,....15,16,17,....20,21,22,....25    (here count is 6)

1)i=5
Here we analyse that at every 5th position we have 5 
so n/5 ->25/5=> 5 

2)i=25
and at 25 we have 2 (5*5)
so n/25 ->25/25=>1 

3)i=125 
here we break the loop.

Return o/p ->6 

Code-:
int trailingZeroes(int n)
{
    int ans=0;
    for(int i=5;i<=n;i=i*5)
    {
      ans+=n/i;
    }
    return ans;
}

