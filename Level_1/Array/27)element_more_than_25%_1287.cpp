Reference->https://www.youtube.com/watch?v=6BoymP9R9MM

Solution 1-:
Steps-:
1)Using map 
2)here we store the frequency of elements 

Code-: Time->O(N) Space->O(N)
int findSpecialInteger(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int>m;
        for(int i=0;i<n;i++)
        {
           m[arr[i]]++;
         }

        int val=n/4+1;
        for(auto x:m)
        {
            if(x.second>=val)
            return x.first;
        }
        return -1;
    }




Solution 2-:
Steps-:
[1,2,2,6,6,6,6,7,10]
1)firstly we calculate the 25% of n  
eg. n=9 then n/4 is 25%
2)here we check if arr[i]==arr[i+n/4] which means there is elements greater than 25%

Dry run-:
1)i=0
[1,2,2,6,6,6,6,7,10]
arr[i]==arr[i+n/4]
arr[0]=!arr[2]

2)i=1
arr[i]==arr[i+n/4]
arr[1]!=arr[3]

3)i=2
arr[i]==arr[i+n/4]
arr[2]==arr[4]
return arr[2]



Code-: Time->O(N) Space->O(1)
int findSpecialInteger(vector<int>& arr) {
        int n=arr.size();
        int index=n/4;
        for(int i=0;i<n;i++)
        {
            if(arr[i]==arr[i+index])
            return arr[i];
        }
        return -1;
    }



Solution 3-:
Steps-:
1)here we are using binary search.
2)we traverse the loop and at each point we check the right side 
  then we check if the (right_side-i+1)>freq it means its freq is greater than 25%.


Code-: Time->O(Nlog(N))
 int helper(vector<int>&arr,int val,int low,int high)
    {
        int ans=low;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(arr[mid]==val)
            {
               ans=mid;
               low=mid+1;
            }
            else
            high=mid-1;
        }
        return ans;
    }
    int findSpecialInteger(vector<int>& arr) {
       int n=arr.size();
       int freq=n/4;
       for(int i=0;i<n;i++)
       {
             int val=arr[i];
             int right_side=helper(arr,val,i,n-1);
             if(right_side-i+1>freq)
             return val;
       }
       return -1;
    }




Solution 4-:
Steps-:
1)Here we are upgrading the upward binary search approach.
2)in up solution we are checking all n elements but here we are using 
  i=freq;i<n ;i+=freq.

   0 1 2 3 4 5 6 7 8
  [1,2,2,6,6,6,6,7,10]

  freq=n/4 => 2 

1) i=2
   here we check left side of 2 and right side of 2 
   if(right-left+1>freq) means this  arr[i] is our answer.

2) i=4
   same

3) i=6 
   same.

4) i=8 
   same 

  we use this approach because it take the range of 


   0 1 2 3 4 5 6 7 8
  [1,2,2,6,6,6,6,7,10]

  i=2 (i=0 to i=2 for left and i=2 to i=n-1 for right)


  Code-:
  int right_side(vector<int>&arr,int val,int low,int high)
    {
        int ans=low;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(arr[mid]==val)
            {
               ans=mid;
               low=mid+1;
            }
            else
            high=mid-1;
        }
        return ans;
    }
    
    int left_side(vector<int>&arr,int val,int low,int high)
    {
        int ans=low;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(arr[mid]==val)
            {
               ans=mid;
               high=mid-1;
            }
            else
            low=mid+1;
        }
        return ans;
    }

    int findSpecialInteger(vector<int>& arr) {
       int n=arr.size();
       int freq=n/4;
       int i=0;
       int val;
       for(int i=freq;i<n;i+=freq)
       {
             int val=arr[i];
             int left=left_side(arr,val,0,i);
             int right=right_side(arr,val,i,n-1);
             if(right-left+1>freq)
             return val;
       }
       return -1;
    }




Solution 5-:
Steps-:
1)just update the above approach for checking three cases-:
  
  i=n/4 , i=n/2 , i=3*n/4
  25%      50%     75%

  0%      25%      50%     75%     100%
          i=0      i=1      i=2


 1) i=0 at 25% cover the left side from 0 to 25% and right side from 25% to 50%.
 2) i=1 at 50% cover the left side from 50% to 25% and right side from 50% to 75%.
 3) i=2 at 75% cover the left side from 75% to 50% and right side from 75% to 100%.

Code-: Time->O(3*log(n)) Space->O(3)
int right_side(vector<int>&arr,int val,int low,int high)
    {
        int ans=low;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(arr[mid]==val)
            {
               ans=mid;
               low=mid+1;
            }
            else
            high=mid-1;
        }
        return ans;
    }
    
    int left_side(vector<int>&arr,int val,int low,int high)
    {
        int ans=low;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(arr[mid]==val)
            {
               ans=mid;
               high=mid-1;
            }
            else
            low=mid+1;
        }
        return ans;
    }

    i
nt findSpecialInteger(vector<int>& arr) {
       int n=arr.size();
       int freq=n/4;
       vector<int>v{n/4,n/2,(3*n)/4};
       for(auto x:v)
       {
             int val=arr[x];
             int left=left_side(arr,val,0,x);
             int right=right_side(arr,val,x,n-1);
             if(right-left+1>freq)
             return val;
       }
       return -1;
    }