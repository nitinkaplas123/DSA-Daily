Solution 1-:
Steps-:
1)First we make a hashmap where we store the freq of nums.
2)here we find the max freq which tells  us that the no. of rows in 2d array.
3)now we traverse the map and put the elements in differnt rows acc to freq.


Code-: Time->O(N^2) Space->O(N)
vector<vector<int>> findMatrix(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>m;

        int count=0;
        for(int i=0;i<n;i++)
        {
            m[nums[i]]++;
            count=max(count,m[nums[i]]);
        }
        vector<vector<int>>v(count);
        for(auto x:m)
        {
            int num=x.first;
            int freq=x.second;

            for(int i=0;i<freq;i++)
            {
                v[i].push_back(num);
            }
        }
        return v;
}