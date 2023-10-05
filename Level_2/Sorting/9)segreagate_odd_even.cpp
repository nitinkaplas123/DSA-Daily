Note->it should be in sorted order

Steps-:
1)using lomuto parition 

Code-: Time->O(nlogn)
void segregateEvenOdd(int arr[], int n) 
{
	    sort(arr,arr+n);
	    int i=-1;
	    for(int j=0;j<n;j++)
	    {
	        if(arr[j]%2==0)
	        {
	            i++;
	            swap(arr[i],arr[j]);
	        }
	    }
	    sort(arr+i+1,arr+n);
}