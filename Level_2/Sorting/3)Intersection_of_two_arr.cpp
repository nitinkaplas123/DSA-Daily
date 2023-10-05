Solution 1-:
Steps-:
1)First we sort both the array
2)Now for unique we make hashset to store if both are same 
3)Now traverse both the arrays and store into hashset.

Code-: Time->O(nlogn) Space->O(N)
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());

        int n1=nums1.size();
        int n2=nums2.size();
        int i=0;
        int j=0;
        
        unordered_set<int>s;
        while(i<n1 and j<n2)
        {
           if(nums1[i]==nums2[j])
           {
               s.insert(nums1[i]);
               i++;
               j++;
           }
           else if(nums1[i]<nums2[j])
           i++;
           else
           j++;
        }
        
        vector<int>v;
        for(auto x:s)
        {
           v.push_back(x);
        }
        return v;
    }



Solution 2-:
Steps-:
1)Make a hashset where we store the arr1 elements into it.
2)Now traverse the arr2 if the nums2 element is present  in hashset then we store that element into ans vector
  and also s.erase(nums2[i])


Code-: Time->O(n+m)  Space ->O(N)
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
       int n1=nums1.size();
       int n2=nums2.size();
       vector<int>ans;
       unordered_set<int>s;
       for(int i=0;i<n1;i++)
       {
           s.insert(nums1[i]);
       }

       for(int i=0;i<n2;i++)
       {
           if(s.find(nums2[i])!=s.end())
           {
               ans.push_back(nums2[i]);
               s.erase(nums2[i]);
           }
       }
       return ans;
    }