Solution 1-:
Steps-:
1)if (N modulo ==0) from i=2 to i=N-1  then its not prime.
2)else its prime.

Prime number are those which are divisible by 1 and number itself.
Code-: Time->O(N)
int isPrime(int N)
{
       if(N==1) return 0;
       for(int i=2;i<N;i++)
       {
           if(N%i==0)
           return 0;
       }
       return 1;
}


Solution 2-:
Steps-:
1)Divisors always appears in pairs.
eg. 30
30  ->(1,30),(2,15),(3,10),(5,6)
means instead of traversing from i=2 to i=n 
we traverse from i=2 to i*i<=n 
which means agr n divisible hoga tu sqrt(N) tak he ho jaega because pair ka 1 number tu hme sqrt(N) tk 
mil jaega agr hoga tu.


Code-: Time->O(sqrt(N))
int isPrime(int N)
{
       if(N==1) return 0;
       for(int i=2;i*i<=N;i++)
       {
           if(N%i==0)
           return 0;
       }
       return 1;
}



Solution 3-:
int isPrime(int N)
{
       if(N==1) return 0;
       if(N==2 || N==3) return 1;
       if(N%2==0 || N%3==0) return 0;
       for(int i=5;i*i<=N;i=i+6)
       {
           if(N%i==0 || (N%(i+2)==0))
           return 0;
       }
       return 1;
}