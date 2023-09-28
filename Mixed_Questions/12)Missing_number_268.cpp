Solution 1-:
Steps-:
1)Using hashset store all the elements there.
2)Now find it using increment the val.

Code-: Time->O(N)  Space ->O(N)
nt missingNumber(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int>s;
        for(int i=0;i<n;i++)
        {
            s.insert(nums[i]);
        }

        int val=0;
        while(s.find(val)!=s.end())
        {
            val++;
        }
        return val;
    }


Solution 2-:
Steps-:
1)Here we know that elements are from [0,n] 
  eg. [0,3,1]  
  missing number is 2
2)Here we do xor of all values and index which give us the missing number 
  
  like here 
  0 index with 0 
  1 index with 3 
  2 index with 1 
 res= 0^0^1^3^2^1
 res=3^2
3)At last we have to xor with n 
  res=res^N
     = 3^2^3
     =>2

O/p is 2 

4)intuition is xor of same value is 0 

Code-: Time->O(n) Space ->O(1)
int missingNumber(vector<int>& nums) 
{
        int n=nums.size();
        int res=0;
        for(int i=0;i<n;i++)
        {
            res=res^nums[i]^i;
        }
        return res^n;
}