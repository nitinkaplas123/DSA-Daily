Reference=> 
dry run-: Notebook 1 -> page=>49

Question -:
Steps-:
Rules-:
1)here questions tells us that alice and bob playing game of picking flower where alice always start picking 
  first.
2)At the end of the turn, if there are no flowers left at all, the current player captures their opponent
  and wins the game.

Conditions-:
1)Alice must win the game according to the described rules.
2)The number of flowers x in the clockwise direction must be in the range [1,n].
3)The number of flowers y in the anti-clockwise direction must be in the range [1,m].



Solution 1-:
Steps-:
1)Run the loop from i=1;i<=n.
2)Run the loop from j=1;j<=m.
3)When (i+j) is odd  count++;
  means that is the pair (i,j) where alice wins.


Code-: Time->O(N*M)
long long flowerGame(int n, int m) {
        long long count=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                int sum=i+j;
                if(sum%2!=0)
                count++;
            }
        }
        return count;
}


Solution 2-:
Steps-:
1)Just count the -:
  1. odd_num_n 
  2. odd_num_m
  3. even_num_n
  4. even_num_m
2)we observe from solution 1-> that when (i+j) pairs sum is odd then alice win.
3)ans+= odd_num_n * even_num_m + odd_num_m * even_num_n.


Code-: Time->O(1)
long long odd(int num)
{
        if(num%2!=0)
        return num/2+1;
        else
        return num/2;
}

long long even(int num)
{
       return num/2;
}

long long flowerGame(int n, int m) {
        long long count=0;
        long long odd_count_n=odd(n);
        long long odd_count_m=odd(m);

        long long even_count_n=even(n);
        long long even_count_m=even(m);

        long long ans=odd_count_n*even_count_m + odd_count_m*even_count_n;
        return ans;
}