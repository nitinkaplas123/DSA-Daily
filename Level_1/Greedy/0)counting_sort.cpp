Counting sort-:
Counting Sort is a linear time sorting algorithm that works well for integers or other discrete data.
It is not a comparison-based sorting algorithm, which means it doesn't rely on comparing elements to
each other. Instead, it counts the number of occurrences of each element in the input data and uses
this information to sort the elements efficiently.


Steps-:
1)First find the maxx element from array and make a array count of that size with intial value 0.
  vector v 
2)Now increase the freq of elements in count array.
  count[v[i]]++
3)Now make a pre_arr array where we do prefix sum of count array. (This give us position or index)
  pre_arr=count[i]+pre_arr[i-1]
4)Now make sort_arr where using-:
  1st give us value 
  3rd give us index where we store the val in correct place.
  sort_arr[index-1]=value

Note->This algo is not recommended when we make element of big size.
for eg.
v=[1,2,1,1000000]
here maxx element is 1000000 size so we have to make this size array which is memory wastage 
Thats why we dont recommend to use this algo for big numbers.


Code-: Time ->O(n)  Space->O(n)
int helper(vector<int>&v)
{ 
    int n=v.size();
    int maxx=INT_MIN;
    //step 1 
    for(int i=0;i<v.size();i++)
    maxx=max(maxx,v[i]);
    
    //step2 
    int count[maxx+1]={0};
    for(int i=0;i<v.size();i++)
    {
        count[v[i]]++;
    }
    
    //step3 
    int pre_arr[maxx+1];
    pre_arr[0]=count[0];
    for(int i=1;i<=maxx;i++)
    {
        pre_arr[i]=count[i]+pre_arr[i-1];
    }
    
    //step4 
    int sort_arr[n];
    for(int i=n-1;i>=0;i--)
    {
        int val=v[i];
        int index=pre_arr[val]-1;
        pre_arr[val]--;
        sort_arr[index]=val;
    } 
}