Solution 1-:
Steps-:
1)storing +ve and -ve number in two differenet vectors.

Code-: Time->O(N) Space->O(2*N)
vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        vector<int>v1;
        vector<int>v2;

        for(int i=0;i<n;i++)
        {
            if(nums[i]>0)
            v1.push_back(nums[i]);
            else
            v2.push_back(nums[i]);
        }

        for(int i=0;i<v1.size();i++)
        {
            ans.push_back(v1[i]);
            ans.push_back(v2[i]);
        }
        return ans;
    }



Solution 2-:
Steps-:
1)Make a ans vector of size n.
2)Now make two varibles even and odd which tells us that at even position we place +ve numbers and 
  at odd posiition we place -ve numbers.

Code-: Time->O(N) Space->O(N) 
vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);

        int even=0;
        int odd=1;
        for(int i=0;i<n;i++)
        {
            if(nums[i]>0)
            {
                ans[even]=nums[i];
                even+=2;
            }
            else
            {
                ans[odd]=nums[i];
                odd+=2;
            }
        }
        return ans;
    }