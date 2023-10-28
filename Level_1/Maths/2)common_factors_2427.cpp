Solution 1-:
A=12
B=6

Factors of 12 ->1,2,3,4,6,12
Factors of 6 ->1,2,3,6
Common->      1,2,3,6 =>4 

int commonFactors(int a, int b) {
       int mini=min(a,b);
       int i=1;
       int count=0;
       for(int i=1;i<=mini;i++)
       {
           if(a%i==0 and b%i==0)
           count++;
       }
       return count;
    }