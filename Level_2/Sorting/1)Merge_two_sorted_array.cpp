leetcode 88 

Solution 1-:
Steps-:
1)Put all the elements of nums2 into nums1
2)Now sort the array 

Code-: Time->O(nlogn)
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
 {
        for(int i=m;i<m+n;i++)
        {
            nums1[i]=nums2[i-m];
        }
        sort(nums1.begin(),nums1.end());
 }


Solution 2-:
Steps-:
1)Find the index=m+n-1;
2)Now using two pointer to end points of num1 and num2 
3)we compare the elements of num1 and nums2 then using it fill the elements at index--;
4)At last if j>=0 then fill all the elements of nums2 into nums1

Code-: Time->O(n+m)  Space ->O(1)
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1;
        int j=n-1;

        int index=m+n-1;
        while(i>=0 and j>=0)
        {
            if(nums1[i]<=nums2[j])
            nums1[index--]=nums2[j--];
            else
            nums1[index--]=nums1[i--]; 
        }

        while(j>=0)
        {
            nums1[index--]=nums2[j--];
        }
    }