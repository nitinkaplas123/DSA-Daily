Solution 1-:
Steps-:
1)Make a vector v and push all into it.
2)Sort the vector v.
3)Now two cases -> if n is even , if n is odd.


Code-: Time->O(N*M +N*Mlog(M*N))  Space->O(N*M)
int Solution::findMedian(vector<vector<int> > &A) {
    vector<int>v;
    int n=A.size();
    int m=A[0].size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            v.push_back(A[i][j]);
        }
    }
    sort(v.begin(),v.end());
    
    int n1=v.size();
    if(n1%2!=0)
    return v[n1/2];
    else
    return (v[n1/2]+v[n1/2-1])/2;
}



Solution 2-:
Steps-:
1)Here we know that we need (r*c+1)/2 numbers less in value in matrix.
  for eg. if we have 9 elements in matrix 
  [1,3,5]
  [2,6,9]
  [3,6,9]

  [1,2,2,3,3,5,6,6,9,9]  here 3 is the median, 4 elements are on left side and 4 elements are on right side.
                         middle element is our median.

2) Desired ->(r*c+1)/2   so here is 5
3) Now here we have to apply the binary search where have to find -:
   low ->from first col 
   high-> from last col.
4)Now (low<high)  low=1   high=9
5) here we have to first find mid->low+high/2
   mid=5
6)Now count the elements in matrix which is less than and equal to 5 using upper_bound.
  here count->5
7)If the count>=desired  (means its greater or equal so it may be our ans but greater than mid we have to delete.)
  so-:
  high=mid;
8) else
   low=mid+1

o/p ->return low or return high.
  

Code-:  Time-> (32*r*logc)
        where 32 is the max iteration of low<high
        where 
int helper(vector<vector<int>>&A,int mid,int r,int c)
{
    int count=0;
    for(int i=0;i<r;i++)     o(r)
    {
        count+=upper_bound(A[i].begin(),A[i].end(),mid)-A[i].begin();  o(log(c))
    }
    return count;
}
int Solution::findMedian(vector<vector<int> > &A) {
    int r=A.size();
    int c=A[0].size();
    
    int low=INT_MAX;
    int high=INT_MIN;
    
    for(int i=0;i<r;i++)
    {
        low=min(low,A[i][0]);
        high=max(high,A[i][c-1]);
    }
    
    int desired=(r*c+1)/2;
    while(low<high)      o(32)      if its of 32 bit.
    {
        int mid=(low+high)/2;
        int count=helper(A,mid,r,c);
        
        if(count>=desired)
        high=mid;
        else
        low=mid+1;
    }
    return high;
}
