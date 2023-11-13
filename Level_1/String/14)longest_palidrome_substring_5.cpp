Reference->https://www.youtube.com/watch?v=UflHuQj6MVA


Solution 1-:
Steps-:
1)find all possible substring and check its palidrome or not 
2)save the longest length substring as answer.

Code-:
bool isPalidrome(string s,int i,int j)
    {
        while(i<j)
        {
           if(s[i]==s[j])
           {
               i++;
               j--;
           }
           else
           return false;
        }
        return true;
    }
    string longestPalindrome(string s) {
        int n=s.length();
        int len=0;
        int start=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                if(isPalidrome(s,i,j))
                {
                   if(len<j-i+1)
                   {
                       len=j-i+1;
                       start=i;
                   }
                }
            }
        }
        return s.substr(start,len);
    }



Solution 2-:
Steps-:
1)Make a dp[n][n]
1)here we make a dp 2d array where if dp[i][j]=1 means from index i to j s.substr(i,j-i+1) is palidrome
  else dp[i][j]=0 tells that its not palidrome.
2)here we know that 1 length of string character is always palidrome so dp[i][i]=1 diagonals 
3)now we go from i=n-2 to i=0  
  and j from j=i+1;j<n.

4) if(s[i]==s[j])        0 1 2 3 4 5 6 7
   there is 2 cases-:    a a a a b b a a 
   i=6 and j=7 
   1)j-i==1 means its palidrome.
   2)when i=3 and j=6 
     s[i]==s[j] and dp[i+1][j-1]==1  means dp[4][5] is palidome.

5)now here we save the starting point and max_len of palidrome.

Code-: Time->O(N2)
string longestPalindrome(string s) {
        int n=s.length();
        int dp[n][n];

        for(int i=0;i<n;i++)
        {
            dp[i][i]=1;
        }
        
        int len=1;
        int start=0;
        for(int i=n-2;i>=0;i--)
        {
            for(int j=i+1;j<n;j++)
            {
                if(s[i]==s[j])
                {
                    if(j-i==1 || dp[i+1][j-1]==1)
                    {
                       dp[i][j]=1;
                       if(len<j-i+1)
                       {
                           start=i;
                           len=j-i+1;
                       }
                    }
                    else
                    dp[i][j]=0;
                }
                else
                dp[i][j]=0;
            }
        }
        return s.substr(start,len);
    }
