Solution -1
Steps-:
1)Sort the array 
2)Make ans=1 and if find ans in array then increment 
3)At last return the ans.

Code-:
int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        
        int ans=1;
        for(int i=0;i<n;i++)
        {
           if(nums[i]==ans)
           ans++;
        }
        return ans;
    }


Solution 2 -:
Steps-:
1)Make a unordered_set and add all elements in it.
2)make ans=1 if s.find(ans) then ans++;
3)Return ans.

Code-:
int firstMissingPositive(vector<int>& nums) {
       int n=nums.size();
       unordered_set<int>s;
       for(int i=0;i<n;i++)
       {
         s.insert(nums[i]);
       }
       
       int ans=1;
       for(int i=0;i<n;i++)
       {
         if(s.find(ans)!=s.end())
         ans++;
       }
       return ans;
    }


Solution -3
Steps-:
1)Find the values which is 0 or less than 0 and store it value as n+1.
2)Make a for loop and make a val as index (val=arr[i]-1) as a abs value.
3)If the val is less than n and its arr[val] is positive(means it should be use earlier)
  then make it as a -ve value.
4)Now here all values are negative which means its present in array and rest which is positive
   there are not present and from starting array if element is +ve means that index+1 is the 
   first missing positive element here.


Code-:
int firstMissingPositive(vector<int>& nums) {
       int n=nums.size();
       for(int i=0;i<n;i++)
       {
         if(nums[i]<=0)
         nums[i]=n+1;
       }
       
       
       for(int i=0;i<n;i++)
       {
         int val=abs(nums[i])-1;
         if(val<n and nums[val]>0)
         {
           nums[val]=-nums[val];
         }
       }

       for(int i=0;i<n;i++)
       {
         if(nums[i]>0)
         return i+1;
       }
       return n+1;
    }



