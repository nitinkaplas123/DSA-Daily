Solution 1-: Using left shift opeartor.
Steps-:
eg. N=4 K=2
1) N=4    -> 100
2 1 0 indexing 
1 0 0

2)here k=2 which means we have to check kth bit 
3)now we are using left shift opeartor 
4) (1<<k)  here we are doing k times left shift opeartor 

5)  0 0 1 
1st 0 1 0 
2nd 1 0 0

6)now doing & opeartor to check.


Code-: Time->O(1)
bool checkKthBit(int n, int k)
{
        return (n & (1<<k));
}



Solution 2-: Using right shift opeartor
Steps-:
N=4 k=2 
1) N=4   1 0 0 
2) here we shift N right shift k times then using & opeartor with it.

    1 0 0 
1st 0 1 0 
2nd 0 0 1

now doing & opeartor with 1 

0 0 1
0 0 1
which is true.


Code-: Time->O(1)
bool checkKthBit(int n, int k)
{
        return (1 & (n>>k));
}