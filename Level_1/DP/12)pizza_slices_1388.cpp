Solution 1-:
Steps-:
1)Using the idea of house robber 2 question.
Code-:
int helper(int index,int n,vector<int>&slices,int k)
{
        if(k==0 || index>=n)
        return 0;

        int take=slices[index]+helper(index+2,n,slices,k-1);
        int not_take=0+helper(index+1,n,slices,k);
        return max(take,not_take);
}

int maxSizeSlices(vector<int>& slices) {
        int n=slices.size();
        int k=n/3;
        int val1=helper(0,n-1,slices,k);
        int val2=helper(1,n,slices,k);
        return max(val1,val2);
}

Solution 2-:
Steps-:
1)Memo.
Here we have 2 variables index and k -:
index = depend upon the array size -> n 
k = n/3

here lets take same size [501][501] no issue.
Code-:
int helper(int memo[501][501],int index,int n,vector<int>&slices,int k)
{
        
        if(k==0 || index>=n)
        return 0;

        if(memo[index][k]!=-1) return memo[index][k];

        int take=slices[index]+helper(memo,index+2,n,slices,k-1);
        int not_take=0+helper(memo,index+1,n,slices,k);
        return memo[index][k]=max(take,not_take);
}

int maxSizeSlices(vector<int>& slices) {
        int n=slices.size();
        int memo1[501][501];
        memset(memo1,-1,sizeof(memo1));
        int memo2[501][501];
        memset(memo2,-1,sizeof(memo2));
        int k=n/3;
        int val1=helper(memo1,0,n-1,slices,k);
        int val2=helper(memo2,1,n,slices,k);
        return max(val1,val2);
}


