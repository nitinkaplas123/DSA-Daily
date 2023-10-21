Solution 1-:
Steps-:
1)Run 2 for loops and make all possible subarray and count it.

Code-: Time->O(n2)  Space ->O(1)
int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int count=0;
        for(int i=0;i<n;i++)
        {
            int sum=0;
            for(int j=i;j<n;j++)
            {
                sum+=nums[j];
                if(sum==k)
                count++;
            }
        }
        return count;
    }



Solution 2-:
Steps-:
1)Here we make hashmap to store the count as value and sum as key.
2)we are using prefix_sum to find the count of subarray those sum is equal to target.

Code-:  Time->O(N)  Space ->O(N)
int subarraySum(vector<int>& nums, int k) 
{
        int n=nums.size();
        int count=0;
        unordered_map<int,int>m;
    
        int pre_sum=0;
        for(int i=0;i<n;i++)
        {
           pre_sum+=nums[i];
           if(pre_sum==k)
           count++;
           
           if(m.find(pre_sum-k)!=m.end())
           count+=m[pre_sum-k];
           
           m[pre_sum]++;
           
        }
        return count;
}


