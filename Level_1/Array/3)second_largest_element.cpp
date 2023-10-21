// Solution -1
// Steps -:
// 1) First Sort the array then take the last element and using this find the second largest.

	int print2largest(int arr[], int n) {
	   sort(arr,arr+n);
	   int first=arr[n-1];
	   for(int i=n-2;i>=0;i--)
	   {
	       if(arr[i]<first)
	       return arr[i];
	   }
	   return -1;
	}


// Solution -2
// Steps-:
// 1) Make the first and second varibale as -1 
// 2) if arr[i]>first then update the second as first and first as arr[i]
// 3) if arr[i]<first and arr[i]>second then update the second=arr[i]

int print2largest(int arr[], int n) {
	   int first=-1;
	   int second=-1;
	   for(int i=0;i<n;i++)
	   {
	       if(arr[i]>first)
	       {
	           second=first;
	           first=arr[i];
	       }
	       else if(arr[i]<first and arr[i]>second)
	       second=arr[i];
	       else
	       continue;
	   }
	   return second;
	}

//Solution -3 

// Steps-:
1) Find the max element in the array.
2) Now find the second largest using condition if(arr[i]>ans and arr[i]!=max_element) 
   then update the ans till the end of loop.

Code-:

int print2largest(int arr[], int n) {
	   int maxi=INT_MIN;
	   for(int i=0;i<n;i++)
	   {
	       maxi=max(maxi,arr[i]);
	   }
	   
	   int ans=INT_MIN;
	   for(int i=0;i<n;i++)
	   {
	       if(arr[i]>ans and arr[i]!=maxi)
	       {
	           ans=arr[i];
	       }
	   }
	   return (ans==INT_MIN)?-1:ans;
	}

