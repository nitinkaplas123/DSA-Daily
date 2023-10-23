Given an integer n, return true if it is a power of four. Otherwise, return false.
An integer n is a power of four, if there exists an integer x such that n == 4x.

Solution 1-:
Steps-:
1)If n is less or equal to 0 then return 0
2)now if n equal to 1 then return 1 bcz 4^0 =1  so if any number is given we have to reach till n==1 
  if it reach at 1 then return 1 else return 0;

Code-:  Time->O(log(n)) base 4 
bool isPowerOfFour(int n) {
        if(n<=0) return 0;
        
        while(n!=1)
        {
           if(n%4!=0) return 0;
           n=n/4;
        }
        return 1;
    }


Solution 2-:
Steps-:
1)we have to check 4^x==n means pow of 4 is equal to x or not.
2)here we use the  formula 
3)First we have to find x then check 4^x==n.
4) log(4^x)=log(n)
   x=log(n)/log(4)
5)Now check if pow(4,x)==n. if yes then return true else return false.


Code-: Time->O(log(n)+log(x))
 bool isPowerOfFour(int n) 
 {
        if(n<=0) return 0;
        
        int x=log(n)/log(4);       time->log(n)
        if(pow(4,x)==n)                ->log(x)
        return 1;
        else
        return 0;
 }
               

Solution 3-:
Steps-:
1)If we need a number which is pow of 4 then its also power of 2 /
  4^x  -> 2^2x 
  means its divisible by 2 
  number should be divisible by 2.

2. Power of  2  (n & (n-1))==0
   eg. n=8
  8-> 1000 
  7-> 0001
  &-> 0000

  eg. n=16
  16-> 10000
  15-> 01111
  &->  00000

3. Now second thing is (n-1)%3==0
  eg. 
  1. n=64 -> (n-1)%3==0
               63%3==0
  2. n=16  -> (15%3==0)
  3. n=4  ->   (3%3==0)
  
  This is the pattern 


4. N=8 
   It is power of 2 but (n-1)%3!=0
   return false.


Code-:
bool isPowerOfFour(int n) 
{
        if(n<=0) return 0;
    
        if(((n&(n-1))==0 and (n-1)%3==0))
        return 1;
        return 0;
}
   