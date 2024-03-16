Solution 1-:
Steps-:
1)here we use hashmap.

Code-: Time->O(N) Space->O(N)
int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        unordered_map<int,int>m;
        int sum=0;
        int count=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            if(sum==goal) count++;
            if(m.find(sum-goal)!=m.end())
            count+=m[sum-goal];
            m[sum]++;
        }
        return count;
}