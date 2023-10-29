Question -:
https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1


Code-:
int minJumps(int arr[], int n){
        if(n==1) return 0;
        if(arr[0]==0) return -1;
        
        int max_reach=arr[0];
        int steps=arr[0];
        int jumps=1;
        for(int i=1;i<n-1;i++)
        {
            max_reach=max(max_reach,i+arr[i]);
            steps--;
            
            if(i==max_reach) return -1;
            
            if(steps==0)
            {
                jumps++;
                steps=max_reach-i;
            }
        }
        return jumps;
    }