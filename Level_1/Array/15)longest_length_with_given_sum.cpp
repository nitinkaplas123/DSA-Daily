Question -:
https://practice.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article


Solution 1-:
Steps-:
1)Using hashmap
2)This question is bit simliar to count length of sum=0;
3)Two cases-:
 1. find from previous map 
    like m[sum-k]!=m.end()
    eg. 
    [10,5,2,7,1,9] 
    using pre_sum concept.

 2. from pre_sum==k 
    eg. 
    [-10,8,2,-2], K=-2

    here -10+8+2+-2=>-2 
    means 4 is the length pre_sum==k
    so here i+1 is the longest length.


Code-: Time->O(N) Space->O(N)
int lenOfLongSubarr(int A[],  int N, int K) 
{ 
       unordered_map<int,int>m;
       int pre_sum=0;
       int ans=0;
       for(int i=0;i<N;i++)
       {
          pre_sum+=A[i];
          if(pre_sum==K)
          ans=max(ans,i+1);
          if(m.find(pre_sum-K)!=m.end())
          ans=max(ans,i-m[pre_sum-K]);
          m.insert({pre_sum,i});
       }
       return ans;
}



SOlution 2-: Only for +ve elements
Steps-:
1)low and high both are at 0 index.
2)if the sum<K then add (sum+=A[high] and high++)
3)if the sum==K then (ans=max(ans,high-low) low++ high++)
4)if the sum>K then (sum-=A[low] and low++)


Code-: Time->O(N) Space->O(1)
 int lenOfLongSubarr(int A[],  int N, int K) 
    { 
       int low=0;
       int high=0;
       
       int sum=0;
       int ans=0;
       while(high<N)
       {
           if(sum==K)
           {
               ans=max(ans,high-low);
               high++;
               low++;
           }
           else if(sum<K)
           {
               sum+=A[high];
               high++;
           }
           else
           {
               sum-=A[low];
               low++;
           }
       }
       return ans;
    }