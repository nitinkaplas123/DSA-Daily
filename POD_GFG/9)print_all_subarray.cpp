given an array [1,2,3]

o/p -> 
[1]
[1,2]
[1,2,3]
[2]
[2,3]
[3]



Solution 1-:
Steps-:
1)Here we clearly see we are using 2 pointer appraoch.
  start and end.
  where start pointing to starting of the index and ending point to end of the array

2) here loop i denotes the starting point of the loop.
3) here loop j denotes the ending point of the loop.
4) solve function print the subarray from (i to j index).

Code-:
void solve(int arr[],int start,int end)
{
    for(int i=start;i<end;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<end;
}
int print(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            solve(arr,i,j);
        }
    }
}
