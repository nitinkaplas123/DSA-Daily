https://practice.geeksforgeeks.org/problems/prime-factors5052/1


Solution 1-:
Code-:
int isPrime(int n)
{
	    if(n==1) return 0;
	    if(n==2 || n==3) return 1;
	    if(n%2==0 || n%3==0) return 0;
	    
	    for(int i=5;i*i<=n;i=i+6)
	    {
	        if(n%i==0 || n%(i+2)==0)
	        return 0;
	    }
	    return 1;
}

vector<int>AllPrimeFactors(int N) 
{
	    vector<int>v;
	    set<int>s;
	    for(int i=2;i<=N;i++)
	    {
	        if(N%i==0)
	        {
	             if(isPrime(i))
	             s.insert(i);
	        }
	    }
	    for(auto x:s)
	    {
	        v.push_back(x);
	    }
	    return v;
}


Solution 2-:
Code-:
vector<int>AllPrimeFactors(int N) {
	    vector<int>v;
	    int i=2;
	    while(N!=1)
	    {
	        if(N%i==0)
	        v.push_back(i);
	        
	        while(N%i==0)
	        {
	            N=N/i;
	        }
	        i++;
	    }
	    return v;
	}



Solution 2-:
Code-:
vector<int>AllPrimeFactors(int N) {
        vector<int>v;
	    set<int>s;
	    
	    for(int i=2;i*i<=N;i++)
        {
          while(N%i==0)
          {
           s.insert(i);
           N=N/i;
          }
        }

	    if(N>1)
	    s.insert(N);
		
	    for(auto x:s)
	    {
	        v.push_back(x);
	    }
	    return v;
	}