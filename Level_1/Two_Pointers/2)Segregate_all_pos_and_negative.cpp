Question link -:
https://practice.geeksforgeeks.org/problems/move-all-negative-elements-to-end1813/1


Code-:  Time->O(N)  Space ->O(N)
 void segregateElements(int arr[],int n)
    {
       int i=-1;
       vector<int>v;
       for(int j=0;j<n;j++)
       {
           if(arr[j]<0)
           v.push_back(arr[j]);
           
           if(arr[j]>0)
           {
               i++;
               swap(arr[i],arr[j]);
           }
       }
       i++;
       for(int j=0;j<v.size();j++)
       {
           arr[i++]=v[j];
       }
    }

