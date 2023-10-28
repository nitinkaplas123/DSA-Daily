Solution 1-:
Steps-:
1)Simple doing multiplicatiton 
  1*2*3*4*5=120

Code-:
long long int factorial(int N){
       long long ans=1;
       for(int i=2;i<=N;i++)
       {
           ans=ans*i;
       }
       return ans;
    }



Solution 2-:
Steps-:
1)Using recursion

Code-:
long long int factorial(int N)
{
      if(N==1 || N==0)
      return 1;
      return N*factorial(N-1);
}

