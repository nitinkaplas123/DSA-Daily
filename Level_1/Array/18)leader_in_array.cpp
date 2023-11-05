Question -:
https://practice.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

Solution 1-:
Steps-:
1)find from right side of array and maintain the largest element from right side.

Code-: Time->O(N) Space->O(1)
vector<int> leaders(int a[], int n){
       vector<int>v;
       v.push_back(a[n-1]);
       int maxx=a[n-1];
       
       for(int i=n-2;i>=0;i--)
       {
            if(a[i]>=maxx)
            {
                v.push_back(a[i]);
                maxx=a[i];
            }
       }
       reverse(v.begin(),v.end());
       return v;
    }