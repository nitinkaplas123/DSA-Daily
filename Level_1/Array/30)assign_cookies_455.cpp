Solution 1-:
Steps-:
1)Sort both the arrays then use 2 pointer approach 

Code-: Time->O(Nlog(N))
int findContentChildren(vector<int>& g, vector<int>& s) {
        int n1=g.size();
        int n2=s.size();
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        
        int i=0;
        int j=0;
        int ans=0;
        while(i<n1 and j<n2)
        {
           if(s[j]>=g[i])
           {
               ans++;
               i++;
               j++;
           }
           else 
           j++;
        }
        return ans;
    }
