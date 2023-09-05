//link
https://practice.geeksforgeeks.org/problems/min-number-of-flips3210/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
alternate means 010101 
Steps-:
S="001"
case 1->010
case 2->101 

case 1->2 flips
case 2 ->1 flip 
o/p =>min(case1,case2) which is  1 


1)Intial c1=0 c2=0 then assume at even position will be filled with 0 and odd with 1
2) if its not as we assume then c1++ c2++
3)At last return min(c1,c2)

Solution-:
int minFlips (string S)
{
    int c1=0;
    int c2=0;
    
    for(int i=0;i<S.size();i++)
    {
        if(i%2==0)
        (S[i]!='0')?c1++:c2++;
        else
        (S[i]!='1')?c1++:c2++;
    }
    return min(c1,c2);
}
