Solution 1-:
Steps-:
1)By visualising the problem.

Code-:
int totalMoney(int n) {
        int count=1;
        int i=1;
        int ans=0;
        while(i<=n)
        {
            int j=count;
            while(j<=(7+count-1) && i<=n)
            {
                ans+=j;
                j++;
                i++;
            }
            count++;
        }
        return ans;
    }


Solution 1-:
Steps-:
1)first we calculate according to weeks.
2)then remaining we add the days to the answer.


Code-: Time->
int totalMoney(int n) {
        int ans=0;
        //weeks
        int weeks=n/7;
        for(int i=0;i<weeks;i++)
        {
            ans+=28+(7*i);
        }
        
        int days=n%7;
        if(days==0) return ans;
        else
        {
            weeks++;
            while(days--)
            {
                ans+=weeks++;
            }
        }
        return ans;
    }
