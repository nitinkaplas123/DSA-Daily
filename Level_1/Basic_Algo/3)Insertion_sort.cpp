Steps-:
1)Take an element place it at a correct position

Code-:
void insertionSort(int arr[], int n)
{
        for(int i=1;i<n;i++)
        {
            int j=i;
            while(j>0 and arr[j-1]>arr[j])
            {
                swap(arr[j-1],arr[j]);
                j--;
            }
        }
}