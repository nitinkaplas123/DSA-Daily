Solution 1-:
Steps-:
1)using 4 loops.
2)we need unique elements in ans vector for that we first sort the array and use set of vectors for unique ans.

Code-: Time->O(n4)  Space ->O(N)

vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        set<vector<int>>s;
        
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                for(int k=j+1;k<n;k++)
                {
                    for(int l=k+1;l<n;l++)
                    {
                        int sum=nums[i]+nums[j]+nums[k]+nums[l];
                        if(sum==target)
                        {
                          s.insert({nums[i],nums[j],nums[k],nums[l]});
                        }
                    }
                }
            }
        }

        for(auto x:s)
        {
            ans.push_back(x);
        }
        return ans;
    }



Solution 2 -:
Steps-:
1)Sort the array 
2)Now run 2 for loop to fix i and j and then low=j+1 and high=n-1 
3)using this we check if sum==target
4)Then store into set of vector for unique combination.


Code-: Time->O(N3)  Space =>O(N)

vector<vector<int>> fourSum(vector<int>& nums, int target) {
       vector<vector<int>>ans;
       set<vector<int>>s;
       int n=nums.size();
       
       sort(nums.begin(),nums.end());
       for(int i=0;i<n-3;i++)
       {
           for(int j=i+1;j<n-2;j++)
           {
              long long int val=target-nums[i];
              val=val-nums[j];
              int low=j+1;
              int high=n-1;

              while(low<high)
              {
                  int sum=nums[low]+nums[high];
                  if(sum==val)
                  {
                      s.insert({nums[i],nums[j],nums[low],nums[high]});
                      low++;
                      high--;
                  }
                  else if(sum<val)
                  low++;
                  else
                  high--;
              }
           }
       }

       for(auto x:s)
       {
           ans.push_back(x);
       }
       return ans;
    }



Solution 3 -:
Steps-:
1)Same as sol 2 just here we dont use set of vector means no extra space we use here.
2)eg [-2,-1,-1,1,1,2,2]  target=0
 i=0 j=1   sum=-3 
 so we need 3 for target=0

 low=2 high=6   -2-1-1+2 =>-2 
 sum<val
 low++;

  low=3 high=6  -2-1+1+2 =>0                 ans={-2,-1,1,2}
  for one move =>low=4 high=5

  now we have while loop for duplicates 
  if(nums[low]==nums[low-1]) low++;

  now we have while loop for duplicates 
  if(nums[high]==nums[high+1]) high--;

3)Now duplicates for first i loop -:
  if(i>0 and nums[i]==nums[i-1])
  continue;

4)Now duplicates for second j loop -:
  if(j!=i+1) and nums[j]==nums[j-1])
  continue;



Code-:  Time ->O(N3)  Space ->O(1)   here we use only extra space to return the ans no extra space we use here.
vector<vector<int>> fourSum(vector<int>& nums, int target) {
       vector<vector<int>>ans;
       int n=nums.size();
       
       sort(nums.begin(),nums.end());
       for(int i=0;i<n-3;i++)
       {
           if(i>0 and nums[i]==nums[i-1]) continue;
           for(int j=i+1;j<n-2;j++)
           {
              if(j!=i+1 && nums[j-1]==nums[j])
              continue;

              long long int val=target-nums[i];
              val=val-nums[j];
              int low=j+1;
              int high=n-1;

              while(low<high)
              {
                  int sum=nums[low]+nums[high];
                  if(sum==val)
                  {
                      vector<int>temp={nums[i],nums[j],nums[low],nums[high]};
                      ans.push_back(temp);
                      low++;
                      high--;
                      while(low<high && nums[low]==nums[low-1])
                      low++;

                      while(low<high && nums[high]==nums[high+1])
                      high--;
                  }
                  else if(sum<val)
                  low++;
                  else
                  high--;
              }
           }
       }
       return ans;
    }



