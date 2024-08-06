Question -> https://www.geeksforgeeks.org/problems/sum-of-all-substrings-of-a-number-1587115621/1

Solution 1-:
Steps-:
1) Make all substring and add.

Code-:
int mod=1e9+7;
long long sumSubstrings(string s){
        long long sum=0;
        for(int i=0;i<s.length();i++)
        {
            for(int j=i;j<s.length();j++)
            {
               string str=s.substr(i,j-i+1);
              // cout<<str<<" ";
               sum+=stoi(str)%mod;
            }
        }
        return (sum%mod);
}



Solution 2-:
Steps-:

Sum of all substrings of a string representing a number using Dynamic-Programming:
To solve the problem follow the below idea:

We can solve this problem by using dynamic programming. We can write a summation of all substrings on basis of the 
digit at which they are ending in that case, 
Sum of all substrings = sumofdigit[0] + sumofdigit[1] + sumofdigit[2] … + sumofdigit[n-1] where n is length of string.
Where sumofdigit[i] stores the sum of all substring ending at ith index digit, in the above example, 

Example: num = “1234”

sumofdigit[0] = 1 = 1
sumofdigit[1] = 2 + 12  = 14
sumofdigit[2] = 3 + 23  + 123 = 149
sumofdigit[3] = 4 + 34  + 234 + 1234  = 1506
Result = 1670

Now we can get the relation between sumofdigit values and can solve the question iteratively.
Each sumofdigit can be represented in terms of previous value as shown below, For above example,

sumofdigit[3] = 4 + 34 + 234 + 1234
                     = 4 + 30 + 4 + 230 + 4 + 1230 + 4
                     = 4*4 + 10*(3 + 23 +123)
                     = 4*4 + 10*(sumofdigit[2])

Formula -:
In general, sumofdigit[i]  =  (i+1)*num[i] + 10*sumofdigit[i-1]


Code-:
int mod=1e9+7;
long long sumSubstrings(string s)
{
      int n=s.length();
      long long int dp[n];
      dp[0]=s[0]-'0';
      long long ans=dp[0];
      for(int i=1;i<n;i++)
      {
         long long int val=s[i]-'0';
         dp[i]= (((i+1)*val)%mod + (10*dp[i-1])%mod)%mod;
         ans+=(dp[i]%mod);
      }
      return ans%mod;
}