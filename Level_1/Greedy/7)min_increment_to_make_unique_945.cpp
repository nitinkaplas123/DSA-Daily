Solution 1-:
Steps-:
1)Sort the array.
2)using observations.

Code-: Time->O(Nlog(N))
int minIncrementForUnique(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());

        int count=0;
        for(int i=1;i<n;i++)
        {
            if(nums[i-1]>=nums[i])
            {
                int diff=nums[i-1]-nums[i];
                count+=(diff+1);
                nums[i]+=(diff+1);
            }
        }
        return count;
}


Solution 2-:
TestCase-:
[3,2,1,2,1,7]

Freq-:
3->1
2->2
1->2
7->1


Steps-:
1)Firstly store the freq of all.
2)Find the maxx element from the array.
3)Now run the loop and if the current freq is greater than 1 then we store the (extra freq in ans variable)
  and shift to just another number which is count[i+1]+=extra.


TestCase -:
[2,2,2,1,2]
why we use (n+maxx_value) not only n.

[11,11,11,11,11]
why we use (n+maxx_value) not only maxx_value.


Code-:
int minIncrementForUnique(vector<int>& nums) {
        int n=nums.size();
        int maxx=0;
        for(int i=0;i<n;i++)
        {
            maxx=max(maxx,nums[i]);
        }
        
        vector<int>count(n+maxx,0);
        for(int i=0;i<n;i++)
        {
            count[nums[i]]++;
        }
        
        int ans=0;
        for(int i=0;i<n+maxx;i++)
        {
           int freq=count[i];
           if(freq>1)
           {
             int diff=freq-1;
             ans+=diff;
             count[i+1]+=diff;
           }
        }
        return ans;
}