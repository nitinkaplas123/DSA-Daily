Solution 1 -:
Steps-:
1)Sort the array 
2)Then there are 3 cases-:
   val=nums[0] count=1
  1)If nums[i]==val+1
    means they are in sequence 
    count++ val=nums[i]

  2)If nums[i]==val
    means nums[i] ==nums[i-1]  
    means here we do not count++ nor count=1 bcz they are same.

  3)else
    means when we  have to start with new layer 
    val=nums[i]
    count=1;


Code-:  Time->O(NlogN)  Space->O(1)
int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());

        if(n==0) return 0;
        
        int val=nums[0];
        int count=1;
        int res=1;
        for(int i=1;i<n;i++)
        {
           if(nums[i]==val+1)
           {
               count++;
               val=nums[i];
           }
           else if(nums[i]==val)
           continue;

           else
           {
             count=1;
             val=nums[i];
           }
           res=max(res,count);
        }
        return res;
    }



Solution 2-:
Steps-:
1)Make a hashset where we store all elements there.
2)Now traverse a loop if we find the element-1 in hashset then we continue;
3)Else we increment the count till we  find the nums[i]+1 element in set.

Code-: Time->O(N)  Space ->O(n)
int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        unordered_set<int>s;
        for(int i=0;i<n;i++)
        {
            s.insert(nums[i]);
        }

        int count=1;
        int res=1;
        for(int i=0;i<n;i++)
        {
            if(s.find(nums[i]-1)!=s.end())
            continue;
            else
            {
               count=1;
               while(s.find(nums[i]+1)!=s.end())
               {
                   count++;
                   nums[i]+=1;
               }
            }
            res=max(res,count);
        }
        return res;
    }


