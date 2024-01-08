Solution 1-:
Steps-:
1)rotate by (0 to k-1)
2)rotate by (k,n-1)
3)rotate by (0,n-1);

Code-: Time->O(N) Space->O(N)
void reverse(int arr[],int low,int high)
{
        while(low<=high)
        {
            swap(arr[low],arr[high]);
            low++;
            high--;
        }
}

void rotateArr(int arr[], int d, int n){
        if(d>n) d=d%n;
        
        reverse(arr,0,d-1);
        reverse(arr,d,n-1);
        reverse(arr,0,n-1);
}