Solution 1-:
Steps-:
1)using hashmap.


Solution 2-:
Steps-:
1)here we first do xor opeartion and store into res varible.
2)now find the first set bit of res from left to right using left shift opeartor.
3)now make 2 variables -: set and unset.
4)Now we traverse the array and check if -:
  if((1<<index) & nums[i]!=0) 
  unset^=nums[i]
  else
  set^=nums[i]

return {set,unset};


Code-: Time->O(N) Space->O(1)

int helper(int res)
{
        for(int i=0;i<32;i++)
        {
            int temp=(1<<i);
            if((temp & res)!=0)
            return i;
        }
        return -1;
}

vector<int> singleNumber(vector<int>& nums) {
        vector<int>v;
        int n=nums.size();

        int res=0;
        for(int i=0;i<n;i++)
        {
            res=res^nums[i];
        }

        int index=helper(res);
       
        int set=0;
        int unset=0;

        for(int i=0;i<n;i++)
        {
            int val=(1<<index);
            if((val & nums[i])==0)
            unset^=nums[i];
            else
            set^=nums[i];
        }
        return {unset,set};
}