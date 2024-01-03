Reference->https://www.geeksforgeeks.org/problems/array-pair-sum-divisibility-problem3257/1

Solution 1-:
Steps-:
1)Make a visited array where we make true if we encounter with pair whose sum is divisble by k.
2)Here we are using 2 for loops.

Code-: Time->O(N^2) Space->O(N)
bool canPair(vector<int> nums, int k) {
       int n=nums.size();
       if(n%2!=0) return false;
       
       
       vector<int>visited(n,false);
       for(int i=0;i<n-1;i++)
       {
           if(visited[i]==false)
           {
            int sum=nums[i];
            for(int j=i+1;j<n;j++)
            {
               if((sum+nums[j])%k==0)
               {
                   visited[i]=true;
                   visited[j]=true;
                   break;
               }
            }
           }
       }
       
       for(int i=0;i<n;i++)
       {
           if(visited[i]==false)
           return false;
       }
       return true;
    }




Solution 2-:
Steps-:
1)