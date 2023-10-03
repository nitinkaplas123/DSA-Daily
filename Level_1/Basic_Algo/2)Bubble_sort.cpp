Steps-:
1)Push the max element to the right side of index by adjacent swaping.


Code-:
void bubbleSort(int arr[], int n)
{
        for(int i=0;i<n;i++)
        {
            bool flag=true;
            for(int j=0;j<n-i-1;j++)
            {
                if(arr[j]>arr[j+1])
                {
                     swap(arr[j],arr[j+1]);
                     flag=false;
                }
            }
            if(flag==true)
            break;
        }
}