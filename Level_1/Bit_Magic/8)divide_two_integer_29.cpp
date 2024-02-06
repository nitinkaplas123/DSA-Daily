Solution 1-:
Steps-:
1)Make a separate case when both are -ve 
2)using long long data type for storing nd return the answer.


Code-:
int divide(int dividend, int divisor) {
       if(dividend==INT_MIN and divisor==-1) return INT_MAX;
       long long res=(long long)dividend /(long long)divisor;
       return (int)res;
    }



Solution 2-:
Steps-:
1)