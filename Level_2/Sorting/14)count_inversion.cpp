Solution 1-:
Steps-:
1)using 2 for loop.

Code-: Time->O(N^2)
long long int inversionCount(long long arr[], long long N)
{
        long long count=0;
        for(int i=0;i<N-1;i++)
        {
            for(int j=i+1;j<N;j++)
            {
                if(arr[i]>arr[j])
                count++;
            }
        }
        return count;
}


Solution 2-:
Steps-:
1)using merge sort 

Code-:
long long merge(long long arr[],int low,int mid,int high)
    {
        int n1=mid-low+1;
        int n2=high-mid;
        
        long long int left[n1];
        long long int right[n2];
        
        for(int i=0;i<n1;i++)
        {
            left[i]=arr[low+i];
        }
        
        for(int i=0;i<n2;i++)
        {
            right[i]=arr[mid+1+i];
        }
        
        int i=0;
        int j=0;
        int k=low;
        long long count=0;
        while(i<n1 and j<n2)
        {
            if(left[i]<=right[j])
            {
                arr[k++]=left[i++];
            }
            else
            {
                count+=(n1-i);
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
        return count;
    }
    long long int mergeSort(long long arr[],int low,int high)
    {
        long long count=0;
        if(low<high)
        {
            int mid=(low+high)/2;
            count+=mergeSort(arr,low,mid);
            count+=mergeSort(arr,mid+1,high);
            count+=merge(arr,low,mid,high);
        }
        return count;
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
       int low=0;
       int high=N-1;
       return mergeSort(arr,low,high);
    }