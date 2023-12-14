Solution 1-:
Steps-:
1)using hashing as this type of question we already do previously.


Code-: Time->O(N) Space->O(N)
int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        unordered_map<int,int>m;

        int pre_sum=0;
        int count=0;
        
        for(int i=0;i<n;i++)
        {
           pre_sum+=nums[i];
           if(pre_sum==goal)
           count++;
           if(m.find(pre_sum-goal)!=m.end())
           count+=m[pre_sum-goal];
           m[pre_sum]++;
        }
        return count;
    }