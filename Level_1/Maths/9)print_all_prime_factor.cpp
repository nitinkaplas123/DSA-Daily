Solution 1-:

Code-: Time->O(Nlog(N))
void primeFactor(int n)
{
    for(int i=2;i<n;i++)  O(N)
    {
        if(isPrime(i))  O(Log(N))
        {
            int x=i;
            while(n%x==0)    O(Log(N))
            {
                v.push_back(i);
                x=x*i;
            }
        }
    }
}



Solution 2-:
Code-:
vector<int> primeFactor(int n)
{
    for(int i=2;i*i<=n;i++)  
    {
       while(n%i==0)
       {
         v.push_back(i);
         n=n/i;
       }
    }

    if(n>1)                   // this is corner case N=35
    v.push_back(n);
    return v;
}

Dry run-:
N=30 (1,30),(2,15),(3,10),(5,6)

means a number n can be written as multiplication of powers of prime numbers 
30-> 2*3*5


Solution 3-:
Code-:
vector<int>AllPrimeFactors(int N) {
        vector<int>v;
	   
	    if(N<=1) return v;
	    if(N%2==0)
	    {
	        while(N%2==0)
	        {
	            v.push_back(2);
	            N=N/2;
	        }
	    }
	    if(N%3==0)
	    {
	        while(N%3==0)
	        {
	            v.push_back(3);
	            N=N/3;
	        }
	    }
	    
	    for(int i=5;i*i<=N;i=i+6)
        {
          while(N%i==0)
          {
            v.push_back(i);
            N=N/i;
          }
          while(N%(i+2)==0)
          {
            v.push_back(i+2);
            N=N/i+2;
          }
        }
	    if(N>3)                  // here we update n>3 as previous we have n>1 bcz we handled n%2==0 and n%3==0 upward 
        
	    v.push_back(N);
	    
	    return v;
	}

  


