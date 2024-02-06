Solution 1-:
Steps-:
1)here we know max size of bits 32.
2)So we do check all bits is its set or not using doing right shift then doing & with 1.

Code-: Time->O(32)
int hammingWeight(uint32_t n) {
        int count=0;
        for(int i=0;i<32;i++)
        {
            if((n>>i &1)==1)
            count++;
        }
        return count;
    }



Solution 2-:
Steps-:
eg N=10 
1010 
1) N=N&(N-1)  
   N=10   1010
   N=9  & 1001
          1000
2) N=8 
   N=8   1000
   N=7 & 0111
         0000

 Here N=0 and total steps to make N=0 is 2 
 which means total set bit is 2.



Code-: Time->O(K) where k is no. of set bits in a given number.
 int hammingWeight(uint32_t n) {
        int count=0;
        while(n!=0)
        {
           n=(n&(n-1));
           count++;
        }
        return count;
    }
       


Solution 3-:
Steps-:
1)Convert the given number into binary representation by dividing 2 and store remainder 
  and count the set bit there.

Code-: Time->O(log(n))
int hammingWeight(uint32_t n) {
       int count=0;
       while(n!=0)
       {
           if(n%2!=0)
           count++;
           n=n/2;
       }
       return count;
    }
