Solution 1-:
Steps-:
1)First we sort the array because we need unique element 
2)For unique we have to sort the array and use the set<vector<int>>s; for storing.

Dry run this case why we need set of vector 
[2,2,2,2,2]

Code-:
vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>v;
        vector<int>v1;
        int n=nums.size();
        set<vector<int>>s;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-3;i++)
        {
            for(int j=i+1;j<n-2;j++)
            {
                for(int k=j+1;k<n-1;k++)
                {
                    for(int l=k+1;l<n;l++)
                    {
                        int sum=nums[i]+nums[j]+nums[k]+nums[l];
                        if(sum==target)
                        {
                            s.insert({nums[i],nums[j],nums[k],nums[l]});
                        }
                    }
                }
            }
        }
        for(auto x:s)
        {
            v.push_back(x);
        }

        return v;
    }



Solution 2-:

Code-: Time->O(N^3) Space->O(N)

vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>v;
        vector<int>v1;
        int n=nums.size();
        set<vector<int>>s;
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n-3;i++)
        {
            for(int j=i+1;j<n-2;j++)
            {
                long long int sum=nums[i]+nums[j];
                int low=j+1;
                int high=n-1;
                while(low<high)
                {
                   long long int val=target-(sum);
                   long long int sum=nums[low]+nums[high];
                   if(sum==val)
                   {
                       s.insert({nums[i],nums[j],nums[low],nums[high]});
                       low++;
                       high--;
                   }
                   else if(sum<val)
                   low++;
                   else
                   high--;
                }
            }
        }

        for(auto x:s)
        {
            v.push_back(x);
        }
        return v;
}