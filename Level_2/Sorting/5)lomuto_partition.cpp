Solution 1-:
Steps-:
1)p is the index pivot=arr[p] (always last element is our pivot)
2)All smaller than pivot is on left side 
3)All greater then pivot is on right side
4)At last we set the pivot element at it correct position 

Code-:
int helper(int arr[],int n,int p)
{
    int val=arr[p];
    int i=-1;
    for(int j=0;j<n;j++)  
    {
        if(arr[j]<val)
        {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    
    swap(arr[i+1],arr[p]);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}