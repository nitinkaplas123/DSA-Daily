Solution 1-:
Steps-:
1)Sort the array in decreasing order of profit.
  So that max profit will be in the starting of the array.
2)Here we make a vector of size n as false.
3)Count will count the job done.
4)for eg. 
  if the deadline is 5 
  so add that profit in index 4 
  thats why we do inner loop on j=deadline-1 to j=0
5)Just do the dry run.

Code-:
static bool comp(Job t1,Job t2)
{
        return (t1.profit>t2.profit);
}

vector<int> JobScheduling(Job arr[], int n) 
{ 
       vector<int>v;
       sort(arr,arr+n,comp);
       
       int profit=0;
       int count=0;
       vector<int>check(n,false);
       for(int i=0;i<n;i++)
       {
          for(int j=arr[i].dead-1;j>=0;j--)
          {
              if(check[j]==false)
              {
                  count++;
                  check[j]=true;
                  profit+=arr[i].profit;
                  break;
              }
          }
       }
       return {count,profit};
} 



Solution 2-:
Steps-:
1)Sort the array in increasing order of deadline.
2)Make a min heap where we complete that particular job which give me maximum profit and at the end we just 
  check the size of pq. (job done=> pq.size())
  int profit=0;
  sum of all the values of pq in variable profit.
  return {jobs,profit}.
3)Make curr=1 for chosing the first element in (0-1) time completion.
4)
  if(arr[i].dead>=curr)
  {
                pq.push(arr[i].profit);
                curr++;
  }
  in this we are adding that profit into pq and curr++.
5)
 else
 {
                if(arr[i].profit>pq.top())
                {
                    pq.pop();
                    pq.push(arr[i].profit);
                }
 }

 here we replace the arr[i].profit with pq.top 
 because at the end we want max profit so here we just replace the min value of pq with arr[i].profit.


Code-:
static bool comp(Job t1,Job t2)
{
        return (t1.dead<t2.dead);
}

vector<int> JobScheduling(Job arr[], int n) 
{ 
        sort(arr,arr+n,comp);
   dsa0900-     priority_queue<int,vector<int>,greater<int>>pq;
        int curr=1;
        for(int i=0;i<n;i++)
        {
            if(arr[i].dead>=curr)
            {
                pq.push(arr[i].profit);
                curr++;
            }
            else
            {
                if(arr[i].profit>pq.top())
                {
                    pq.pop();
                    pq.push(arr[i].profit);
                }
            }
        }
        
        int ans=0;
        int jobs=pq.size();
        while(pq.empty()==false)
        {
            ans+=pq.top();
            pq.pop();
        }
        return {jobs,ans};
} 
