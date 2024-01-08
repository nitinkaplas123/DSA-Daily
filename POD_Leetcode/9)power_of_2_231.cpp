Solution 1-:
Steps-:
1)given n should be power of 2.
2)so pow(2,x)==n.
3)for that we have to calculate  x 
  2^x=n.
  taking log both side-:
  x=log(n)/log(2)
4)Now return (pow(2,x)==n)


Code-: Time->O(log(N))
bool isPowerOfTwo(int n) {
       if(n<=0) return 0;
       int x=(log(n)/log(2));
       if(pow(2,x)==n)
       return 1;
       else
       return 0;
}



Solution 2-:
Steps-:
1)if n%2!=0 return false 
2)else n=n/2 if we get n==1 return true;

Code-: Time->O(log(N))
bool isPowerOfTwo(int n) {
       if(n<=0) return 0;
       while(n!=1)
       {
           if(n%2!=0) return 0;
           n=n/2;
       }
       return 1;
}



Solution 3-:
Steps-:
1)if n is  power of 2 
  then (n & (n-1))==0.
2)eg. 
  n=8 
  1000
  n=7
  0111

  1000
  0111
 &
  0000 


Code-:
bool isPowerOfTwo(int n) {
       if(n<=0) return 0;
       return ((n & (n-1))==0);
}