Question link-> https://www.geeksforgeeks.org/problems/smallest-window-containing-0-1-and-2--170637/1

Solution 1-:
Steps-:
1)using 2 for loop
2)make a hashset for checking all 012 in it.

Code-: Time->O(N^2) Space->O(N)
int smallestSubstring(string S) {
        int n=S.length();
        int ans=INT_MAX;
        for(int i=0;i<n-2;i++)
        {
            unordered_set<int>set;
            for(int j=i;j<n;j++)
            {
                set.insert(S[j]-'a');
                if(set.size()==3)
                {
                    ans=min(ans,j-i+1);
                    break;
                }
            }
        }
        return (ans==INT_MAX)?-1:ans;
    }



Solution 2-:
Steps-:
1)using hashmap and sliding window and 2 pointer 


Code-: Time->O(2*N) Space->O(N) or O(3)
int smallestSubstring(string S) {
        int n=S.length();
        int ans=INT_MAX;
        unordered_map<char,int>m;
        
        int low=0;
        int high=0;
        while(high<n)
        {
            m[S[high]]++;
            while(m.size()==3)
            {
                ans=min(ans,high-low+1);
                m[S[low]]--;
               
                
                if(m[S[low]]==0)
                m.erase(S[low]);
                low++;
            }
            high++;
        }
        return (ans==INT_MAX)?-1:ans;
    }





Solution 3-:
Steps-:
1)using array of size 3 
2)adding current value freq in it.
3)while loop condition if all 3 freq>0 
  then we store the ans and shrink the window from starting.


Code-: Time->O(2*N) Space->O(3)
 int smallestSubstring(string S) {
        int n=S.length();
        int ans=INT_MAX;
        vector<int>count(3,0);
       
        int low=0;
        int high=0;
        while(high<n)
        {
            count[S[high]-'0']++;
           
            while(count[0]>0 and count[1]>0 and count[2]>0)
            {
                ans=min(ans,high-low+1);

                count[S[low]-'0']--;
                low++;
            }
            high++;
        }
        return (ans==INT_MAX)?-1:ans;
    }