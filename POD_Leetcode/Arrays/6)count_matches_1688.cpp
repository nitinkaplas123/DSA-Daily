Solution 1-:
Steps-:
1)If n is odd different logic nd if even its different.

Code-: Time->O(logn) 
int numberOfMatches(int n) {
        int ans=0;
        while(n!=1)
        {
           ans+=n/2;
           if(n%2!=0)
           n=n/2+1;
           else
           n=n/2;
        }
        return ans;
    }