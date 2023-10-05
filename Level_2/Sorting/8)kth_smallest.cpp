Solution 1 -:
Steps-:
1)sort the array
2)find the k-1 element in array

Code-: Time->O(nlogn)  Space ->O(1)
int kthSmallest(int arr[], int l, int r, int k) 
{
       sort(arr,arr+r+1);
       return arr[k-1];
}


Solution 2-:
Steps-:
1)Using max_heap 
2)Make a heap of size k 
3)now traverse a loop from k to n-1 if pq.top()>arr[i] then remove the top element and push that arr[i]
4)At last we have kth smallest element at top of k size heap.

Code-: Time->O(nlog(k)) Space ->o(k)
int kthSmallest(int arr[], int l, int r, int k) 
{
      priority_queue<int>pq;
      for(int i=0;i<k;i++)
      {
          pq.push(arr[i]);
      }
      
      for(int i=k;i<=r;i++)
      {
          if(pq.top()>arr[i])
          {
              pq.pop();
              pq.push(arr[i]);
          }
      }
      return pq.top();
 }
Solution 3-: using lomuto partition

Steps-:
1)Find pivot using partition 
2)if(p==k-1) return arr[p]
3)if p is greater then r=p-1
4)else l=p+1

Code-: Time->On average ->O(N) 
int partition(int arr[],int l,int h)
{
        int i=l-1;
        int pi = l + (rand()%(h-l+1));
        swap(arr[pi],arr[h]);
        
        int pivot=arr[h];
        
        for(int j=l;j<=h;j++)
        {
            if(arr[j]<pivot)
            {
                i++;
                swap(arr[i],arr[j]);
            }
        }
        swap(arr[i+1],arr[h]);
        return i+1;
}

int kthSmallest(int arr[], int l, int r, int k) 
{
      while(l<=r)
      {
          int p=partition(arr,l,r);
          if(p==k-1)
          return arr[p];
          else if(p>k-1)
          r=p-1;
          else
          l=p+1;
      }
      return 100;
}
