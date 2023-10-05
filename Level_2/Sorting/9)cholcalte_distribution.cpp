Solution 1-:
Steps-:
1)Here we have to sort the array 
2)we have to find the min diff bw maxi-mini
3)using two pointer i=0 j=m-1 
4)now find the min diff

Code-: Time->O(nlogn)  Space ->O(1)

long long findMinDiff(vector<long long> a, long long n, long long m)
{
       sort(a.begin(),a.end());
       
       int i=0;
       int j=m-1;
       long long ans=INT_MAX;
       while(j<n)
       {
           ans=min(ans,a[j]-a[i]);
           i++;
           j++;
       }
       return ans;
 }   