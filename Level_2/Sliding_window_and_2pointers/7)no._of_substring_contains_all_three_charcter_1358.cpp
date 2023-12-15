Reference ->Notebook 1 Page No. ->40 
Solution 1-:
Steps-:
1)make a array of size 3 and add its freq there.
2)using 2 for loops make all subarray and check if count arry consist all 3 charcters.

Code-: Time->O(N^2) Space->O(1)
int numberOfSubstrings(string s) {
        int n=s.length();
        int ans=0;
        for(int i=0;i<n-2;i++)
        {
            vector<int>count(3,0);
            for(int j=i;j<n;j++)
            {
                count[s[j]-'a']++;
                if(count[0] and count[1] and count[2])
                ans++;
            }
        }
        return ans;
    }



Solution 2-:

1)
s={a,b,c,a,b,c}
o/p -> 10 

{a,b,c}
{a,b,c,a},{b,c,a}
{a,b,c,a,b},{b,c,a,b},{c,a,b}
{a,b,c,a,b,c},{b,c,a,b,c},{c,a,b,c},{a,b,c}



Simple Inution is 
         l   h 
   0 1 2 3 4 5
s={a,b,c,a,b,c}

1)if in index ->3 to index->5 {a,b,c} is there    {3,5} is one window 
  so if we count all left side that is also containing {a,b,c} 

  those window are -> 
  1){0,5} 
  2){1,5}
  3){2,5}
  
  Rest u can check in page 40 notebook ->1 
  
          