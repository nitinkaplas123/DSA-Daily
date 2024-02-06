Solution 1-:

Code-:
int findGCD(vector<int>& nums) {
        int n=nums.size();
        int mini=nums[0];
        int maxi=nums[0];
        for(int i=1;i<n;i++)
        {
            mini=min(mini,nums[i]);
            maxi=max(maxi,nums[i]);
        }
       
        int val=mini;
        for(int i=val;i>=1;i--)
        {
            if(maxi%i==0 and mini%i==0)
            return i;
        }
        return 1;
    }



Solution 2-:
Steps-:
1)Using euclidean algorithms 
2)Pls see its approve in detail.

Code-:
int findGCD(vector<int>& nums) {
        int n=nums.size();
        int mini=nums[0];
        int maxi=nums[0];
        for(int i=1;i<n;i++)
        {
            mini=min(mini,nums[i]);
            maxi=max(maxi,nums[i]);
        }
       
        int num1=mini;
        int num2=maxi;
        while(num1!=num2)
        {
            if(num1>num2)
            num1=num1-num2;
            else
            num2=num2-num1;
        }
        return num1;
    }




Solution 3-:
Steps-:
1)Optimised approach

Code-:  
 int helper(int a,int b)
    {
        if(b==0) return a;
        return helper(b,a%b);
    }
    int findGCD(vector<int>& nums) {
        int n=nums.size();
        int mini=nums[0];
        int maxi=nums[0];
        for(int i=1;i<n;i++)
        {
            mini=min(mini,nums[i]);
            maxi=max(maxi,nums[i]);
        }
       
        int num1=mini;
        int num2=maxi;
        
        return helper(num1,num2);
    }