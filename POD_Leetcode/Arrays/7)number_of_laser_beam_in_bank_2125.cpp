Solution 1-:
Steps-:
1) here we make a array where we store the count of set bit of each string.
2) now we make 2 pointer prev=0 and curr=1 
3) if count[curr]==0 means no laser beam make bw index=curr so we continue it.
4) if count[curr]!=0 than we make ans=>curr*prev and make prev=curr for making next iteration.


Code-: Time->O(M*N) Space->O(N) where N is the no. of rows.
int numberOfBeams(vector<string>& bank) {
        int n=bank.size();
        vector<long long int>v;
        for(int i=0;i<n;i++)
        {
            long long int count=0;
            int m=bank[i].length();
            for(int j=0;j<m;j++)
            {
               if(bank[i][j]=='1')
               count++;
            }
            v.push_back(count);
        }

        long long int ans=0;
        int prev=0;
        
        for(int curr=1;curr<n;curr++)
        {
            if(v[curr]==0)
            continue;
            else
            {
                ans+=(v[curr]*v[prev]);
                prev=curr;
            }
        }
        return ans;
    }




Solution 2-:
Steps-:
1)Here instead of storing into vector we calculate everytime and make use of prev and curr.


Code-: Time->O(M*N) Space->O(1)
int helper(string str)
    {
        int count=0;
        for(auto x:str)
        {
            if(x=='1')
            count++;
        }
        return count;
    }
    int numberOfBeams(vector<string>& bank) {
        int n=bank.size();

        long long int ans=0;
        
        int prev=helper(bank[0]);
        for(int i=1;i<n;i++)
        {
            int curr=helper(bank[i]);
            
            if(curr==0)
            continue;
            else
            {
                ans+=(curr*prev);
                prev=curr;
            }
        }
        return ans;
    }