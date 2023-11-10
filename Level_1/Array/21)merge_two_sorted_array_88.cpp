Steps-:
1)Using two pointer approach 


Solution 1-:
Code-: Time->O(n+m) Space->O(1)
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int size=m+n;
        int index=size-1;
        int i=m-1;
        int j=n-1;

        while(i>=0 and j>=0)
        {
            if(nums1[i]<=nums2[j])
            {
                nums1[index--]=nums2[j--];
            }
            else
            nums1[index--]=nums1[i--];
        }

        while(j>=0)
        {
            nums1[index--]=nums2[j--];
        }
    }