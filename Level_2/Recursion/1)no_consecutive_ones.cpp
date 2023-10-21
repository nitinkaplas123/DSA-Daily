1)N = 2
Output: 3
Explanation: 3 strings are
(00,01,10).

2)N = 3
Output: 5
Explanation: 5 strings are (000,
001, 010, 100, 101).

3)N=4
o/p -> 8
Here we see the pattern of fibonacci series.

f[n]=f[n-1]+f[n-2];


Solution 1-:
Steps-:
1)Here we see the pattern of fibonaci series.
2)
when n=1 o/p -> 2    1 , 0   there is no consecutive ones 
when n=2 o/p -> 3
when n=3 o/p->  5
when n=4 o/p ->8

so its pure fibonaci series questions


Code-: Time->O(N)  where n is the given number in input.
int mod=1e9+7;
	ll countStrings(int n) {
	    if(n==1 || n==2)
	    return n+1;
	    int a=2;
	    int b=3;
	    long long int c;
	    for(int i=3;i<=n;i++)
	    {
	        c=(a+b)%mod;
	       // cout<<c<<endl;
	        a=b;
	        b=c;
	    }
	    return c;
	}

Solution 2-:  Time->O(N)  Space->O(N)
Steps-:
Using Dynamic programming.

Code-:
int mod=1e9+7;
	ll countStrings(int n) {
	   int fib[n+1];
	   fib[0]=1;
	   fib[1]=2;
	   for(int i=2;i<=n;i++)
	   {
	       fib[i]=(fib[i-1]+fib[i-2])%mod;
	   }
	   return fib[n];
	}



