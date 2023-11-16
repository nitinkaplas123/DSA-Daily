Solution 1-:
Code-: Time->O(Nlog(N))
int isPrime(int n)
{
        if(n<=1) return 0;
        if(n==2 || n==3) return 1;
        if(n%2==0 || n%3==0) return 0;

        for(int i=5;i*i<=n;i=i+6)
        {
            if(n%i==0 || n%(i+2)==0)
            return 0;
        }
        return 1;
}

int countPrimes(int n) {
        int count=0;
        for(int i=2;i<n;i++)   O(N)
        {
            if(isPrime(i))     O(Log(N))
            count++;
        }
        return count;
    }




Solution 2-:
Code-:

sieve of erathosis 

