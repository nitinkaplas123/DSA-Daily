Solution 1-:
Steps-:

1)All you need to do is count the number of set bits in A ^ B and you will have your answer.
2)You can do this using the kernighans algorithm as in the code below.

Code-: Time->O(N) where N is no. of set bit in n 
 int minBitFlips(int start, int goal) {
        int n=start^goal;

        int count=0;
        while(n!=0)
        {
            n=(n & (n-1));
            count++;
        }
        return count;
    }