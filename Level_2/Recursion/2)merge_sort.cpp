Solution 1-:
Steps-:
1)First we divide the array -:
  from low to mid 
  then from mid+1,high    until we reach l<r
2)Now we merge 
  for eg. [4,1,3,9,7]

  low=0,mid=2,high=4

  just example last 

 we store into left and right array
 left=> [1,3,4]                   right=> [7,9]

 Now we merge both array 
 while merge 
 i=0;                                 j=0;
 i<n1                                 j<n2

 k=l of that array because when we merge right side into array we have to add into correct position.
 for eg.
 [4,1,3,9,7]

  when we do merge for   [9,7]
  [4,1,3]                here 9 is at index 3 
                         so here k=l 
                         k=3 
                         then we make it at its correct position.
                         [7,9]
                                  
  

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
       
       int i=0;
       int j=0;
       int k=l;
       while(i<n1 and j<n2)
       {
           if(left[i]<right[j])
           {
               arr[k]=left[i];
               k++;
               i++;
           }
           else
           {
               arr[k]=right[j];
               k++;
               j++;
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
       if(l<r)
       {
           int mid=(l+r)/2;
           mergeSort(arr,l,mid);
           mergeSort(arr,mid+1,r);
           merge(arr,l,mid,r);
       }
    }