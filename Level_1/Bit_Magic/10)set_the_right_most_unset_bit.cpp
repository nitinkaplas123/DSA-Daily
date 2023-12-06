Question -:
https://www.geeksforgeeks.org/problems/set-the-rightmost-unset-bit4436/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article


Solution 1-:
Steps-:
1)Find the right most unset bit.

There is 2 cases-:
1)N=15 -> 1111
here we find the 4 bit as unset but its wrong we need to find inbetween of it.

like -> 0 1 1 1 1
here our logic given 0 at 4 so it gives us N +pow(2,i)=> 15 + 16 =>31 
which is wrong


2)so we have to make the logic if N<pow(2,i)  -> return N 

3) else we have to do return N+pow(2,i);



Code-: Time->O(Log(n))
int setBit(int N)
{
       int i;
       for(i=0;i<32;i++)
       {
           if((1<<i & N)==0)
           break;
       }
       if(pow(2,i)>N) return N;
       else
       return N+ pow(2,i);
}