Solution 1-:

Diagram -:
Notebook 1 page 38
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



Solution 2-:
Reference->https://www.youtube.com/watch?v=b7AYbpM5YrE

Steps-:
1)if we have n no. of element in array then we have pow(2,n) subset.
2)Here we are using 2 loops 
3)outer loop i=0 to i<pow(2,n)
4)inner loop give the element using right shift opeator.


Code-:  Time->O(2^n *n)
vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        int p=pow(2,n);
        vector<vector<int>>v(p);

        for(int i=0;i<p;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(1<<j & i)
                v[i].push_back(nums[j]);
            }
        }
        return v;
    }
