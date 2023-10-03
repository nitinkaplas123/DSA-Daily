Question link-:
https://practice.geeksforgeeks.org/problems/count-the-triplets4615/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article


Solution 1 -:
Steps-:
1)Sort the array.
2)Make a hashset and put all values there.
3)Now run a 2 loops can make a pair of  two number and check if this sum is present in hashset.
  If yes then count++;

Code-:  Code->O(N2)  Space->O(N)
int countTriplet(int arr[], int n)
	{
	    unordered_set<int>s;
	    for(int i=0;i<n;i++)
	    {
	        s.insert(arr[i]);
	    }
	    
	    sort(arr,arr+n);
	    
	    int count=0;
	    for(int i=0;i<n-1;i++)
	    {
	        for(int j=i+1;j<n;j++)
	        {
	            int sum=arr[i]+arr[j];
	            if(s.find(sum)!=s.end())
	            count++;
	        }
	    }
	    return count;
	}



Solution 2 -:
Steps-:
1)Sort the array.
2)Make 3 variables low=0,high=n-1,mid=high-1;
3)Run the while loop where high>=2 bcz we need low and mid also.
4)Run the loop low<mid
5)If sum=arr[low]+arr[mid]==arr[high] then count++ low++ mid--
6)If sum<arr[high]  means sum is less so we have to increase by low++;
7)If sum>arr[high] means sum is greater we have to decrease it so mid--;
8)When low<mid break means for fixing the high at end point all combination we see now 
  low=0
  high-- 
  mid=high-1


Code-:
int countTriplet(int arr[], int n)
	{
	    sort(arr,arr+n);
	    int count=0;
	    int low=0;
	    int high=n-1;
	    int mid=high-1;
	    while(high>=2)
	    {
	        while(low<mid)
	        {
	            int sum=arr[low]+arr[mid];
	            if(sum==arr[high])
	            {
	                count++;
	                low++;
	                mid--;
	            }
	            else if(sum<arr[high])
	            low++;
	            else
	            mid--;
	        }
	        low=0;
	        high--;
	        mid=high-1;
	    }
	    return count;
	}


Code in js-:
countTriplet(arr,n){
        let s=new Set()
	    for(let i=0;i<n;i++)
	    {
	        s.add(arr[i]);
	    }
	    
	    arr.sort(function(a,b){return a-b});
	    
	    let count=0;
	    for(let i=0;i<n-1;i++)
	    {
	        for(let j=i+1;j<n;j++)
	        {
	            let sum=arr[i]+arr[j];
	            if(s.has(sum))
	            count++;
	        }
	    }
	    return count;
    }