https://www.geeksforgeeks.org/problems/modular-exponentiation-for-large-numbers5537/1

Solution 1-:
Steps-:
1)Using normal Multiplication.

Code-:
long long int PowMod(long long int x,long long int n,long long int M)
{
		  long long int ans=1;
		  for(int i=0;i<n;i++)
		  {
		      ans=(ans*x)%M;
		  }
		  return (ans%M);
}

Solution 2-:
Steps-:
1)Using recursion.
2)Here first we find the temp by dividing by 2.
3)Because of dividing by 2 we have to multiple the temp=temp*temp.
4)if n is odd then we have to multiple by x.
5)Return temp.
6)Do the dry run.

long long int PowMod(long long int x,long long int n,long long int M)
{
		    if(n==0)
		    return 1;
		    
		    long long int temp=PowMod(x,n/2,M);
		    temp=((temp%M) * (temp%M)%M);
		    
		    if(n%2!=0)
		    temp=(temp*x)%M;
		    return temp%M;
}

