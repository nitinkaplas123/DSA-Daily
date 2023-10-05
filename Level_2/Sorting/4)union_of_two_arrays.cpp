Solution 1-:
Steps-:
1)Make a hashset where we add all the elements of arr1 and arr2 into it.
2)Now add all the values of set into vectors.


Code-: Time->O(nlogn)  Space ->o(n)
vector<int> findUnion(int arr1[], int arr2[], int n, int m)
{
       vector<int>v;
       set<int>s;
       for(int i=0;i<n;i++)
       {
           s.insert(arr1[i]);
       }
       for(int i=0;i<m;i++)
       {
           s.insert(arr2[i]);
       }
       
       for(auto x:s)
       {
           v.push_back(x);
       }
       return v;
}


Solution 2-:
Steps-:
1)Using v.back() we can check not to enter the duplicates values into ans vector.


Code-:  Time->O(N)  Space ->O(1)
 vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
      vector<int>v;
      int i=0,j=0;
       
      while(i<n and j<m)
      {
             if(arr1[i]==arr2[j])
             {
              if(v.empty()==true || v.back()!=arr1[i])
              v.push_back(arr1[i]);
              i++;
              j++;
             }
             else if(arr1[i]<arr2[j])
             {
              if(v.empty()==true || v.back()!=arr1[i])
              v.push_back(arr1[i]);
              i++;
             }
             else
             {
              if(v.empty()==true || v.back()!=arr2[j])
              v.push_back(arr2[j]);
              j++;
             } 
      }
       
      while(i<n)
      {
          if(v.empty()==true || v.back()!=arr1[i])
          v.push_back(arr1[i]);
          i++;
      }
       
      while(j<m)
      {
          if(v.empty()==true || v.back()!=arr2[j])
          v.push_back(arr2[j]);
          j++;
      }
      return v;
    }