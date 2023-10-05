Steps-:
1)Here first we have to divide the array into two parts till the 1 and 1 elements in both arrays.
2)Then we apply merge two sorted array logic 
3)here we make two arrays left and right where we store the elements there.
4)Now we sorted both the arrays and put the sorted array into original arrays till last.



Code-:
void merge(int arr[], int l, int m, int r)
    {
        int n1=m-l+1;
        int n2=r-m;
        
        int left[n1];
        int right[n2];
        
        for(int i=0;i<n1;i++)
        {
            left[i]=arr[l+i];
        }
        
        for(int i=0;i<n2;i++)
        {
            right[i]=arr[m+1+i];
        }
        
        int i=0,j=0,k=l;
        
        while(i<n1 and j<n2)
        {
            if(left[i]<=right[j])
            {
                arr[k++]=left[i++];
            }
            else
            {
                arr[k++]=right[j++];
            }
        }
        
        while(i<n1)
        {
            arr[k++]=left[i++];
        }
        
        while(j<n2)
        {
            arr[k++]=right[j++];
        }
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
       if(r>l)
       {
           int mid=l+(r-l)/2;
           mergeSort(arr,l,mid);
           mergeSort(arr,mid+1,r);
           merge(arr,l,mid,r);
       }
    }