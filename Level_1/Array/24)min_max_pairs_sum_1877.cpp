Solution 1-:
Steps-:
1)sort the array and using low=0 high=n-1 we find the max sum using this approach.

Code-: Time->O(Nlog(N))
int minPairSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int low=0;
        int high=n-1;
        int ans=INT_MIN;
        while(low<high)
        {
            int sum=nums[low]+nums[high];
            ans=max(ans,sum);
            low++;
            high--;
        }
        return ans;
    }

In js-:
var minPairSum = function(nums) {
    nums.sort(function(a,b){return a-b});
    let low=0;
    let high=nums.length-1;
    let ans=-Infinity;

    for(let i=0;i<nums.length;i++)
    {
        console.log(nums[i]);
    }
    while(low<high)
    {
        let sum=nums[low]+nums[high];
        ans=Math.max(ans,sum);
        low++;
        high--;
    }
    return ans;
};


Solution 2-:
Steps-:
Approach 🚀
1)Frequency Counting and Finding Min/Max:

Iterate through the given array to calculate the frequency of each number and find the minimum (minNum) and maximum (maxNum) numbers.

2)Initialize Pointers and Iterate:
Initialize two pointers, low pointing to minNum and high pointing to maxNum.
Iterate using a while loop until low is less than or equal to high.

3)Adjust Pointers:
If the frequency of the number at low is zero, move low to the right to find the next valid number.
If the frequency of the number at high is zero, move high to the left to find the next valid number.

4)Pairing and Updating MaxSum:
If both low and high pointers point to valid numbers, calculate the sum of the pair (currentPairSum).
Update the maxSum if the currentPairSum is greater.
Decrease the frequency of the numbers at low and high pointers.

5)Return Result:
After the while loop, return the final minimized maximum pair sum stored in maxSum.


Code-:
int minPairSum(vector<int>& nums) {
       int n=nums.size();
       int mini=INT_MAX;
       int maxi=INT_MIN;
       for(int i=0;i<n;i++)
       {
           mini=min(mini,nums[i]);
           maxi=max(maxi,nums[i]);
       }

       unordered_map<int,int>m;
       for(int i=0;i<n;i++)
       {
           m[nums[i]]++;
       }

       int low=mini;
       int high=maxi;
       int ans=INT_MIN;
       while(low<=high)
       {
           if(m[low]==0)
           low++;

           else if(m[high]==0)
           high--;
           else
           {
               int sum=low+high;
               ans=max(ans,sum);
               m[low]--;
               m[high]--;
           }
       }
       return ans;
    }