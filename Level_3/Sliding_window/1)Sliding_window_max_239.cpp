Solution 1-:
Steps-:
1)Using traverse k times in every time.

Code-: Time->O(N*K) Space->O(1)
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>v;
        
        for(int i=0;i<=n-k;i++)
        {
            int ans=INT_MIN;
            for(int j=i;j<k+i;j++)
            {
                ans=max(ans,nums[j]);
            }
            v.push_back(ans);
        }
        return v;
    }



Solution 2-:
Steps-:
Here we use deque data struture because in this question we use both front and back to solve this problem.

For first k index
1)In first loop we traverse k index where we store index in dq and at front of deque we store max element
  with in k element.
2)if the current element is greater than nums[dq.back()] then we pop_back the index from the dq.
3)If its smaller element then we insert into dq.

For k to n index
1)As we know we have to max of k element so firstly we check its (current index - front index+1)> K
  means if dq size is greater than k we have to delete from pop_fron()
2)Now if the current element > nums[dq.back()] then pop_front 
3)Now add the current index at dq.back() 
4)Now add the pop_front to our ans

Note->Key idea is in every window front index is max of k index (means element)

Code-: Time->O(N) Space->O(K)
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>v;
        
        deque<int>dq;
        dq.push_front(0);
        for(int i=1;i<k;i++)
        {
            while(dq.empty()==false and nums[i]>nums[dq.back()])
            {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        v.push_back(nums[dq.front()]);

        for(int i=k;i<n;i++)
        {
            if(i-dq.front()+1>k)
            dq.pop_front();
            
            while(dq.empty()==false and nums[i]>nums[dq.back()])
            {
                dq.pop_back();
            }
            dq.push_back(i);
            v.push_back(nums[dq.front()]);
        }
        return v;
    }