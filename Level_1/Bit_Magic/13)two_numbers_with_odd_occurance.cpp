Solution 1-:
Steps-:
1)Using hashmap

Code-: Time->O(N) Space->O(N)
vector<long long int> twoOddNum(long long int Arr[], long long int N)  
{
      unordered_map<int,int>m;
      for(int i=0;i<N;i++)
      {
          m[Arr[i]]++;
      }
       
      vector<long long>v;
      for(auto x:m)
      {
          if(x.second%2!=0)
          v.push_back(x.first);
      }
      if(v[0]>v[1])
      return v;
      else
      return {v[1],v[0]};
}



Solution 2-:
Steps-:
Arr = {4, 2, 4, 5, 2, 3, 3, 1}
1)First a fall we do the xor of all the elements in array.
   ans=4^2^4^5^2^3^3^1=> 4 
   ans= 100
2)Now we have to find the index of first set bit from right side.
  index=2 

3) 4-> 100
   2-> 010
   4-> 100
   5-> 101
   2-> 010
   3-> 011
   3-> 011
   1-> 001

ans 4->100

4)Using ans binary representation we know that index-> 2 in ans is set which means this is index where 
  5 and 1 is not matching which is answer,
5)We make 2 separate varibles -> set and unset where we separate the array elements according to index 2 
6) set      unset 
   4        2
   4        2
   5        3 
            3
            1
xor 5       1
7)doing xor for both   

8)now we can return the {5,1}




Code-: Time->O(N) 
    int helper(int ans)
    {
        int i;
        for(i=0;i<32;i++)
        {
            if((1<<i) &ans)
            break;
        }
        return i;
    }
    vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
      int ans=0;
      for(int i=0;i<N;i++)
      {
          ans^=Arr[i];
      }
      
      int index=helper(ans);
      
      long long int set=0;
      long long int unset=0;
      for(int i=0;i<N;i++)
      {
          if((1<<index) & Arr[i])
          set^=Arr[i];
          else
          unset^=Arr[i];
      }
      if(set>unset)
      return {set,unset};
      else
      return {unset,set};
    }