Solution 1-:
Steps-:
1)Using 2 for loops

Code-: Time->O(n2)
int firstRepeated(int arr[], int n) 
{
  for(int i=0;i<n;i++)
  {
    for(int j=i+1;j<n;j++)
        {
              if(arr[i]==arr[j])
              return i+1;
        }
  }
  return -1;
}


Solution 2-:
Steps-:
1)Storing all key value in map.
2)Now traverse the for loop of array now check if its freq>1 then its return i+1; 

Code-: Time->O(N) Space ->O(N)
int firstRepeated(int arr[], int n) 
{
      unordered_map<int,int>m;
      for(int i=0;i<n;i++)
      {
          m[arr[i]]++;
      }
      
      for(int i=0;i<n;i++)
      {
          int freq=m[arr[i]];
          if(freq>=2)
          return i+1;
      }
      return -1;
}  