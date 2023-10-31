Solution 1-:
Steps-:
1)Using 4 for loops

Code-: Time->O(n^4)
int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n=nums1.size();
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                for(int k=0;k<n;k++)
                {
                    for(int l=0;l<n;l++)
                    {
                        int sum=nums1[i]+nums2[j]+nums3[k]+nums4[l];
                        if(sum==0)
                        count++;
                    }
                }
            }
        }
        return count;
    }



Solution 2-:
Steps-:
1)Here we store it nums4 array in map why map 
  because we have duplicate values like ->
  num4[]=[1,1,1,3,3]

  if we need 1 to make sum=0 from num4 so in num4 we have 3 1s thats why we use map.


Code-: Time->O(n^3) Space->O(N)
int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n=nums1.size();
        unordered_map<int,int>m;
        for(int i=0;i<n;i++)
        {
            m[nums4[i]]++;
        }

        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                for(int k=0;k<n;k++)
                {
                    int sum=nums1[i]+nums2[j]+nums3[k];
                    if(m.find(-sum)!=m.end())
                    count+=m[-sum];
                }
            }
        }
        return count;
    }


Solution 3-:
Steps-:
1)Here we store the all combination of arr3 and arr4 in map.

Code-: Time->O(N^2) Space->O(n)
int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n=nums1.size();
        unordered_map<int,int>m;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
             int sum=nums3[i]+nums4[j];
             m[sum]++;
            }
        }

        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int sum=nums1[i]+nums2[j];
                if(m.find(-sum)!=m.end())
                count+=m[-sum];
            }
        }
        return count;
    }
};