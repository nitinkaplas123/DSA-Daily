Solution 1-:
Steps-:
1)Make a isPrime array mark all as true.
2)Run a loop from i=2 to i*i<=n 
  now if(isPrime[i]==true)
3)Do its multiple as false 
  from j=2*i;j<n;j+=i

Dry run the case N=25
u see outer loop is run for i=2,3,5
and make all its multiple as false 

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
Steps-:
1)just replace (2*i) with (i*i) because its save the itertion 
  and sometime we already check the value which we again check in case of 2*i.

Code-: Time->O(Nlog(log(n)))
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