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



Solution 2-:
Steps-:
1)Using recusrion.
2)here we calling 2 function for printing.

Code-:
void helper1(int N,vector<int>&v,int val)
    {
        v.push_back(N);
        
        if(N<=0)
        return ;
        
        helper1(N-5,v,val);
    }
    
    void helper2(int N,vector<int>&v,int val)
    {
        v.push_back(N);
        
        if(N==val) return ;
        
        helper2(N+5,v,val);
    }
    
    vector<int> pattern(int N){
       vector<int>v;
       int val=N;
       v.push_back(N);
       if(N<=0) return v;
       helper1(N-5,v,val);
       helper2(v.back()+5,v,val);
       return v;
    }



Solution 3-:
Steps-:
1)Using recursion single function 

Code-: Time->O(N)
 void helper(int N,vector<int>&v)
    {
        v.push_back(N);
        if(N<=0) return ;
        helper(N-5,v);
        v.push_back(N);
    }
    vector<int> pattern(int N){
        vector<int>v;
        helper(N,v);
        return v;
    }