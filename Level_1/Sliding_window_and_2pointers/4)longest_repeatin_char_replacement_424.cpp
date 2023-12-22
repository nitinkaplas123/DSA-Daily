Solution 1-:
Steps-:
1)here we are making array v of size 26 with intial value =0.
2)here we are using 2 pointer with sliding window approach low and high.
Three cases-:
1)intially we increment the count 
   v[s[high]-'A']++;

2)Now we have to find the maxx freq in array v.
   int maxx=0;
   for(int i=0;i<26;i++)
   {
      maxx=max(maxx,v[i]);
   }

3) Now here the main logic is suppose 
  s="AABABBA", k = 1

  0 1 2 3 4 5 6
  A A B A B B A     K=1

  1)In window 0 to 2 
  we have ->AAB 
  length ->3 
  maxx freq in array -> 2   which is of A.
  we can use k charcter replacemenet which is 1 here.
             
             if (window-maxx<=k) which tells the replacemenet char is less or equal to k
             then this window is consider as our answer.
  formula -> if(high-low+1 - maxx<=k)


 2)if window is not consider means replacemenet char in window>k then we have to remove the charter from window
   using low pointer.

   if(high-low+1-maxx>k)
   {
     v[s[low]-'A']--;
     low++;
   }


 
Code-: Time->O(26*N) Space->O(26)
int characterReplacement(string s, int k) {
        int n=s.length();
        vector<int>v(26,0);
        int low=0;
        int high=0;
        int ans=0;
        while(high<n)
        {
            v[s[high]-'A']++;
            // most 
            int maxx=0;
            for(int i=0;i<26;i++)
            {
               maxx=max(maxx,v[i]);
            }
            if(high-low+1-maxx>k)
            {
                v[s[low]-'A']--;
                low++;
            }
            ans=max(ans,high-low+1);

            high++;
            cout<<ans<<endl;
        }
        return ans;
    }




Solution 2-:
Steps-:
1)Here we just decreases the time complexity where we find the maxx freq in vector (26).
 // maxx frequency
            maxx=max(maxx,v[s[high]-'A']);

2)here we just store the maxx freq using checking vector v freq.

3)Note that when we compress the window from low pointer at that point we are decrease the maxx store value 
  but we store the previous maxx value but it doesnot effective our answer bcz prev maxx window we already 
  store into our answer now answer is change when maxx increase it value.


Code-: Time->O(N) Space->O(26)
int characterReplacement(string s, int k) {
        int n=s.length();
        vector<int>v(26,0);
        int low=0;
        int high=0;
        int ans=0;
        int maxx=0;
        for(int high=0;high<n;high++)
        {
            v[s[high]-'A']++;
            
            // maxx frequency
            maxx=max(maxx,v[s[high]-'A']);
            // when window need more replacement than k we have to 
            // shift the low from starting.
            if(high-low+1-maxx>k)
            {
                v[s[low]-'A']--;
                low++;
            }
            ans=max(ans,high-low+1);
        }
        return ans;
    }