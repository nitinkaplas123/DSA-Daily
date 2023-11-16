Solution -1
Steps-:
1)Make a hashset for storing nums1.
2)Now run a loop for nums2 array and find if nums2[i] is prsent in hashset -:
  Case 1
  If present then add into ans vector and erase that value from set bcz we need unique elements 

  Case 2
  Continue

Code-: Time ->O(N)  Space->O(N)

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>v;
        unordered_set<int>s;
        for(int i=0;i<nums1.size();i++) s.insert(nums1[i]);

        for(int i=0;i<nums2.size();i++) 
        {
            if(s.find(nums2[i])!=s.end())
            {
                v.push_back(nums2[i]);
                s.erase(nums2[i]);
            }
        }
        return v;
    }


Solution -2
Steps-:
1)Sort both the arrays 
2)Then using two pointer we can solve it.

Code-: Time->O(NlogN)  Space->o(1)

vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
{
        int n1=nums1.size();
        int n2=nums2.size();
        vector<int>v;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());

        int i=0,j=0;
        while(i<n1 and j<n2)
        {
           if(nums1[i]==nums2[j])
           {
               if(v.size()==0)
               v.push_back(nums1[i]);
               else if(v.back()!=nums1[i])
               v.push_back(nums1[i]);
    
               i++;
               j++;
           }
           else if(nums1[i]<nums2[j])
           i++;
           else
           j++;
        }
        return v;
}



Js Code-:
ar intersection = function(nums1, nums2) {
        let n1=nums1.length;
        let n2=nums2.length;
        let v=new Array()
        nums1.sort(function(a,b) {return a-b})
        nums2.sort(function(a,b){return a-b})

        let i=0,j=0;
        while(i<n1 && j<n2)
        {
           if(nums1[i]==nums2[j])
           {
               if(v.length==0)
               v.push(nums1[i]);
               else if(v.slice(-1)!=nums1[i])
               v.push(nums1[i]);
    
               i++;
               j++;
           }
           else if(nums1[i]<nums2[j])
           i++;
           else
           j++;
        }
        return v;
};