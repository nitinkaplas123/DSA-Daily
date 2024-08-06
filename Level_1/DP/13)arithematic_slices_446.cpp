Code-:
int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        int res=0;
        unordered_map<long long,int>m[n]; 

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                long long int diff=(long long)nums[i]-nums[j];
                auto it=m[j].find(diff);
                
                int count_at_j=(it==end(m[j])?0:it->second);
                m[i][diff]+=(count_at_j+1);
                res+=count_at_j;
            }
        }
        return res;
}