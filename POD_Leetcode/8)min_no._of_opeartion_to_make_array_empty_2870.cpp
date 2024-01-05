Solution 1-:
Steps-:
1)Make a hashmap where we store the freq of it.
2)Now there is 3 cases-:
Case 1-:
If freq/3==0 then 
ans+=freq/3

Case 2-:
If freq==1  
return -1; bcz we cannot empty the array using these two condition.

Case 3-:
freq=freq-2
ans++;


Code-: Time->O(N) Space->O(N)
int minOperations(vector<int>& nums) {
        int n=nums.size();

        unordered_map<int,int>m;
        for(int i=0;i<n;i++)
        {
            m[nums[i]]++;
        }
 
        int ans=0;
        for(auto x:m)
        {
           int freq=x.second;
           while(freq!=0)
           {
               if(freq%3==0)
               {
                   ans+=freq/3;
                   break;
               }
               else if(freq>=2)
               {
                   ans++;
                   freq-=2;
               }
               else
               return -1;
           }
        }
        return ans;
    }




Solution 2-:
Steps-:
1)It uses a map mp to calculate the frequency of each number in nums.
2)If any number occurs only once in nums, its impossible to achieve the desired pattern,
  so the function returns -1.
3)It calculates the number of moves needed to make all occurrences of each number a multiple
  of 3. If there are remaining occurrences (not divisible by 3), it adds one more move for 
  each such occurrence.
4)Finally, it returns the total number of moves needed to achieve the desired pattern.


Code-: Time->O(N) Space->O(N)
int minOperations(vector<int>& nums) {
        int n=nums.size();

        unordered_map<int,int>m;
        for(int i=0;i<n;i++)
        {
            m[nums[i]]++;
        }
 
        int ans=0;
        for(auto x:m)
        {
            int freq=x.second;
            if(freq==1)
            return -1;
            else  
            ans+=freq/3;

            if(freq%3!=0)
            ans++;
        }
        return ans;
    }