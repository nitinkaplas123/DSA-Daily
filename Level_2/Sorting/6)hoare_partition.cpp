Steps-:
1)Always assume pivot at first posiition 
2)i=l-1;  
3)j=h+1;

Code-:

int partition(int arr[],int l,int n,int h)
{
    int pivot=arr[l];
    int i=l-1;
    int j=h+1;

    while(1)
    {
        //find the greatest index at left side
        do{
            i++;
        }while(arr[i]<pivot);

        //find the smallest index at right side
        do{
            j--;
        }while(arr[j]>pivot);

        if(i>=j) break;

        swap(arr[i],arr[j]);
    }
}

here pivot is not at its correct position 