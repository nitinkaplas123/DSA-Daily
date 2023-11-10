Solution 1-:
Steps-:
1)Using 2 loops

Code-: Time->O(N)
int Solution::solve(vector<int> &A, int B) {
    int n1=A.size();
    int count=0;
    for(int i=0;i<n1;i++)
    {
        int sum=0;
        for(int j=i;j<n1;j++)
        {
            sum=sum^A[j];
            if(sum==B)
            count++;
        }
    }
    return count;
}

Solution 2-:

int Solution::solve(vector<int> &A, int B) {
        int n=A.size();
   
        int count=0;
        
        unordered_map<int,int>m;
        m[0]=1;
        int sum=0;
        for(int i=0;i<n;i++)
        {
          sum=sum^A[i];
          if(m.find(sum^B)!=m.end())
          count+=m[sum^B];
        
          m[sum]++;
        }
        return count;
}

