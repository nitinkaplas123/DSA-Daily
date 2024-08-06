Steps-:
1)sort the array and if nums[i-1]>=nums[i] then ans++;

Code-: Time->O(n2)   Space ->O(1)

int minIncrementForUnique(vector<int>& nums) 
{
      sort(nums.begin(),nums.end());
      int n=nums.size();
      int ans=0;
      for(int i=1;i<n;i++)
      {
         while(nums[i-1]>=nums[i])
         {
             ans++;
             nums[i]+=1;
         }
      }
      return ans;
}




Solution->2    Time ->O(nlogn)    Space ->O(N)

Steps-:
1)If current element is not present in hashset then simply add into it.
2)If current element is present then -:
  case 1 ->for ans
  ans=ans+abs(last_element_in_set-nums[i])+1   (+1 is for increasing)
  s.insert(nums[i]+1)

Code-:
int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<int>s;
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            if(s.find(nums[i])==s.end())
            s.insert(nums[i]);
            else
            {
               int last=*--s.end();
               ans=ans+abs(last-nums[i])+1;
               s.insert(last+1);
            }
        }
        return ans;
    }



Solution -3 Time ->O(nlogn)   Space->O(1)

Idea-:
The idea is to sort the input -O(nlogn)- , then we move forward from the beginning of the array till the end.
As soon as we found a condition that the current element is less than or equal to the previous elements then we need to update the current array element.
here is an example of the given input.
A = [3,2,1,2,1,7]
Sorted A = [1,1,2,2,3,7]
After reaching the second 1 on the array since the condition is satisfied A[i]<=A[i-1] so we need to update the A[i] by A[i-1]+1.
At the same time we need to keep track of result by
result += A[i-1]+ 1 - A[i];

The rest of iterations are as following :

A = [1,2,2,2,3,7]
res= 1

A = [1,2,3,2,3,7]
res= 2

A = [1,2,3,4,3,7]
res= 4

A = [1,2,3,4,5,7]
res= 6



Code-: Time->O(NLog(N)) Space->O(1)
int minIncrementForUnique(vector<int>& nums) {
      sort(nums.begin(),nums.end());
      int n=nums.size();
      int ans=0;
      for(int i=1;i<n;i++)
      {
          if(nums[i-1]>=nums[i])
          {
              ans+=nums[i-1]-nums[i]+1;
              nums[i]=nums[i-1]+1;
          }
      }
      return ans;
}

