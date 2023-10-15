Solution 1-:
Steps-:
1)Checking at every index using 2 for loops.


Code-: Time->O(n2) Space->O(1)

 int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        for(int i=0;i<n;i++)
        {
            int petrol=0;
            for(int j=i;j<n+i;j++)
            {
                int index=j%n;
                 petrol+=gas[index];
                 petrol-=cost[index];
                 if(petrol<0) break;
            }
            if(petrol>=0)
            return i;
        }
        return -1;
    }



Solution 2-:
Steps-:
1) here if at index i our (curr+=gas[i]-cost[i]) become negative means before this i its positive this current
   index i will become this negative so its clear that none of the index from 0 to i index will be our ans.
2) Now our  ans will be i+1 to n-1 index.
3) so if our curr become negative at index i then we start new means curr=0; before become it zero we have to
   save curr in prev
   if(curr<0)
   {
    start=i+1;
    prev+=curr;
    curr=0
   }
4)here we store prev because if we calculate from i+1 to index we also check from 0 to i for index=i+1
  for this we store it in prev varible.
5)At last if 
  curr+prev>=0?start_index 
  else
  return -1 because there is no index which satisfied this condition.


 
Code-: Time->O(N) Space->O(1)
nt canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int prev=0;
        int curr=0;
        int start=0;
        for(int i=0;i<n;i++)
        {
           curr+=gas[i]-cost[i];
           if(curr<0)
           {
               prev+=curr;
               start=i+1;
               curr=0;
           }
        }
        return (curr+prev>=0)?start:-1;
    }