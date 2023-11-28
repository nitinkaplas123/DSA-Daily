Question -:
https://www.geeksforgeeks.org/problems/print-pattern3549/1

Solution 1-:
Steps-:
1)here we use while loop for printing the values.

Code-: Time->O(N) 
vector<int> pattern(int N){
       int val=N;
       vector<int>v;
       v.push_back(N);
       
       while(N>0)
       {
           N=N-5;
           v.push_back(N);
       }
       
       while(val!=N)
       {
           N=N+5;
           v.push_back(N);
       }
       return v;
    }