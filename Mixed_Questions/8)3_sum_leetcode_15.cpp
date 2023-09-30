Solution 1-:
Steps-:
1)Same steps what we do in countTriplet problem
2)Here we need to store triplets unique for that we are using set of vector after that we put that vector
  into ans 2d vector.


Code-: Code->O(n2)  Space ->O(N)
vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        set<vector<int>>s1;
        vector<int>v;
        
        int n=nums.size();
        sort(nums.begin(),nums.end());

        int low=0;
        int high=n-1;
        int mid=high-1;
        while(high>=2)
        {
            while(low<mid)
            {
                int sum=nums[low]+nums[mid]+nums[high];
                if(sum==0)
                {
                    s1.insert({nums[low],nums[mid],nums[high]});
                    low++;
                    mid--;
                }
                else if(sum<0)
                low++;
                else
                mid--;
            }
            low=0;
            high--;
            mid=high-1;
        }
        
        for(auto x:s1)
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
