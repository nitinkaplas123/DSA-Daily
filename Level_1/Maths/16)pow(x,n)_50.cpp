Solution 1-:
Steps-:
1)if n<0 then we have to find abs(n) then do 1/ans.
2)else  we do normal 

Code-: Time->O(log(N))
double helper(double x,int n)
    {
        if(n==0)
        return 1;

        double temp=helper(x,n/2);
        temp=temp*temp;
        if(n%2!=0)
        return x*temp;
        else
        return temp;
    }
    
    double myPow(double x, int n) {
        if(n<0)
        {
            double res=helper(x,abs(n));
            double ans=1/double(res);
            return ans;
        }
        else
        return helper(x,n);
    }
