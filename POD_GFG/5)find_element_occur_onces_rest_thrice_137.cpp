Solution 1-:
Steps-:
1)using hashmap.

Code-: Time->O(N) Space->O(N)
int singleElement(int arr[] ,int N) {
        unordered_map<int,int>m;
        for(int i=0;i<N;i++)
        {
            m[arr[i]]++;
        }
        
        for(auto x:m)
        {
            if(x.second==1)
            return x.first;
        }
        return -1;
    }




Solution 2-:
Steps-:
1)sort the array 
2)then compare i element with i-1 and i element with i+1

Code-: Time->O(Nlog(N)) Space->O(1)
int singleNumber(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());

        if(n==1) return nums[0];

        if(nums[0]!=nums[1]) return nums[0];
        if(nums[n-2]!=nums[n-1]) return nums[n-1];

        for(int i=1;i<n-1;i++)
        {
            if(nums[i]!=nums[i-1] and nums[i]!=nums[i+1])
            return nums[i];
        }
        return -1;
    }




Solution 3-: 

Steps-:
1)Count the number of set bit at every bit from 0 to 32 for every n.
2)if count%3!=0 count is not multiple of three which means here single element having bit there.
  so we add ans+=pow(2,j);

Code-: Time->O(32*N) Space->O(1)    
int singleNumber(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int j=0;j<32;j++)
        {
            int count=0;
            for(int i=0;i<n;i++)
            {
                if(((1<<j) & nums[i])!=0)
                count++;
            }
            cout<<count<<endl;
            if(count%3!=0)
            ans+=(1<<j);
        }
        return ans;
    }















































































































































































