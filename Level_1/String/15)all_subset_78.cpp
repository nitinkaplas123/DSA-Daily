Solution 1-:
Steps-:
1)using recusrion 
2)Two recusrive function 
  1st is for not included
  2nd is for included


Code-:
void helper(vector<int>nums,int index,vector<int>v1,vector<vector<int>>&v)
    {
        if(index==nums.size())
        {
            v.push_back(v1);
            return ;
        }
        
        //not included 
        helper(nums,index+1,v1,v);
        
        //included
        v1.push_back(nums[index]);
        helper(nums,index+1,v1,v);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>v;
        vector<int>v1;
        int index=0;

        helper(nums,index,v1,v);
       
        return v;
    }