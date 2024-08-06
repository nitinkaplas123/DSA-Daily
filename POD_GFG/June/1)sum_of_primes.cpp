https://practice.geeksforgeeks.org/problems/sum-of-prime4751/1


Solution 1-:
Steps-:
1)Firstly we make vector prime where we store all the prime number there.
2)Put all the values of prime in set.
3)Now i am checking if n-prime[i] is present in set or not.


Code-: Time->O(N*sqrt(N))
int isPrime(int n)
{
        if(n==2 || n==3)
        return true;
        if(n%2==0 || n%3==0)
        return false;
        
        for(int i=5;i*i<=n;i+=6)
        {
            if(n%i==0 || (n%(i+2)==0))
            return false;
        }
        return true;
}

vector<int> getPrimes(int n)
{
        vector<int>prime;
        for(int i=2;i<=n;i++)
        {
            if(isPrime(i))
            prime.push_back(i);
        }
        
        unordered_set<int>s;
        for(int i=0;i<prime.size();i++)
        {
            s.insert(prime[i]);
        }
        
        for(int i=0;i<prime.size();i++)
        {
            if(s.find(n-prime[i])!=s.end())
            return {prime[i],n-prime[i]};
        }
        return {-1,-1};
}


Solution 2-:
Steps-:
1)Make a isPrime vector of sieve of erasthosis.
2)Now we know that prime no. is marked as true rest all is false.

Code-: Time->O(N*log(log(N)))
vector<int> getPrimes(int n) 
{
        vector<int>isPrime(n+1,true);
        isPrime[0]=false;
        isPrime[1]=false;
        
        for(int i=2;i*i<=n;i++)
        {
            if(isPrime[i]==true)
            {
                for(int j=i*i;j<=n;j+=i)
                {
                    if(isPrime[j]==true)
                    isPrime[j]=false;
                }
            }
        }
        
        for(int i=2;i<=n;i++)
        {
            if(isPrime[i]==true and isPrime[n-i]==true)
            return {i,n-i};
        }
        return {-1,-1};
}