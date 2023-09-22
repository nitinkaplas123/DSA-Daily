Steps-:
1)Selection sort means select the minimum element then swap with the starting index
2)Repeat the step 1 until to reach the last index.


Code-:  Time->O(n2)
void selectionSort(int arr[], int n)
{
       for(int i=0;i<n;i++)
       {
           int min_index=i;
           for(int j=i+1;j<n;j++)
           {
               if(arr[min_index]>arr[j])
               min_index=j;
           }
           swap(arr[i],arr[min_index]);
       }
}