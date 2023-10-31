Solution 1-:
Steps-:

Code-:
int countPrimes(int n) {
        vector<int>isPrime(n+1,true);
        for(int i=2;i<=n/2;i++)
        {
            if(isPrime[i]==true)
            {
                for(int j=2*i;j<n;j+=i)
                {
                    if(isPrime[j]==true)
                    isPrime[j]=false;
                }
            }
        }
        int count=0;
        for(int i=2;i<n;i++)
        {
            if(isPrime[i]==true)
            count++;
        }
        return count;
    }



Solution 2-:
Code-:
int countPrimes(int n) {
        vector<int>isPrime(n+1,true);

        for(int i=2;i*i<=n;i++)
        {
            if(isPrime[i]==true)
            {
                for(int j=i*i;j<n;j+=i)
                {
                    isPrime[j]=false;
                }
            }
        }

        int count=0;
        for(int j=2;j<n;j++)
        {
            if(isPrime[j])
            count++;
        }
        return count;
    }