Solution 1-:
Steps-:
1)Using 2 for loop.



Solution 2-:
Steps-:
1)using sorting.
2)Then compare curr element with prev.

Code-: Time->O(Nlog(N))
bool containsDuplicate(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());

        for(int i=1;i<n;i++)
        {
            if(nums[i]==nums[i-1])
            return true;
        }
        return false;
    }


Solution 2-:
Steps-:
1)using hashmap 

Code-: Time->O(N) Space->O(N)
bool containsDuplicate(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>m;
        for(int i=0;i<n;i++)
        {
            m[nums[i]]++;
            if(m[nums[i]]>=2)
            return true;
        }
        return false;
    }




Solution 4-:
Steps-:
1)Using hashset 
2)her we add all the elements in hashset.
3)now if the size of set == n which means there is no duplicate if not equal then it means 
  there is duplicate in array.



Code-: Time->O(N) Space->O(N)
bool containsDuplicate(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int>s;
        for(int i=0;i<n;i++)
        {
            s.insert(nums[i]);
        }
        return (n!=s.size());
}