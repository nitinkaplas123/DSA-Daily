Solution 1-:
Steps-:
1)Same steps what we do in countTriplet problem
2)Here we need to store triplets unique for that we are using set of vector after that we put that vector
  into ans 2d vector.


Code-: Code->O(n2)  Space ->O(N)
vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        set<vector<int>>s1;
        vector<int>v;
        
        int n=nums.size();
        sort(nums.begin(),nums.end());

        int low=0;
        int high=n-1;
        int mid=high-1;
        while(high>=2)
        {
            while(low<mid)
            {
                int sum=nums[low]+nums[mid]+nums[high];
                if(sum==0)
                {
                    s1.insert({nums[low],nums[mid],nums[high]});
                    low++;
                    mid--;
                }
                else if(sum<0)
                low++;
                else
                mid--;
            }
            low=0;
            high--;
            mid=high-1;
        }
        
        for(auto x:s1)
        {
            ans.push_back(x);
        }
        return ans;
    }




