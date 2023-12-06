Reference=> https://www.youtube.com/watch?v=pH7E4Ny7EnU&t=385s

Question 1-:
Here we find the xor from 1 to N 

Solution 1-:
Steps-:
1)Using normal xor of numbers

Code-: Time->O(N)
 int findXOR(int l, int r) {
       int ans=0;
       for(int i=l;i<=r;i++)
       {
           ans=ans^i;
       }
       return ans;
    }



Solution 2-:
Steps-:
1)There is a pattern in this question we have to analyse that.

             sum of xor
1 -> 001 ->        1
2 -> 010 -> 011 -> 3 
3 -> 011 -> 000 -> 0
4 -> 100 -> 100 -> 4

5 -> 101 -> 001 -> 1
6 -> 110 -> 111 -> 7
7 -> 111 -> 000 -> 0
8 -> 1000 ->1000 ->8

9 -> 1001 ->0001 ->1
10-> 1010 ->1011 ->11
11-> 1011 ->0000 ->0
12-> 1100 ->1100 ->12

2) There is pattern after every 4 numbers.
3) There is 4 pattern we see in this.
  1. N%4==0
     answer -> N 
  2. N%4==1
     answer ->1 
  3. N%4==2
     answer ->N+1
  4. N%4==3
     answer ->0



Code-: Time->O(1)
int xor(int n)
{
    if(n%4==0)
    return n;
    else if(n%4==1)
    return 1;
    else if(n%4==2)
    return n+1;
    else
    return 0;
}




Question 2-:
Here we have to find the xor in the range  

eg .
Find xor in l=4 to r=8
means -> 4^5^6^7^8 -> 8

Now 
Steps-:
1)find the xor from 1 to 8 ->   ans1
2)find the xor from 1 to 3 ->   ans2
3)now return ans1^ans2;

(1^2^3^4^5^6^7^8)  ^ (1^2^3)
so here 1,2,3 is cancelled with themselves 
rest are (4^5^6^7^8)



Code-:Time->O(1)
int helper(int n)
{
         if(n%4==0)
         return n;
         else if(n%4==1)
         return 1;
         else if(n%4==2)
         return n+1;
         else
         return 0;
}
    
int findXOR(int l, int r) {
       int ans1=helper(r);
       int ans2=helper(l-1);
       return ans1^ans2;
}

