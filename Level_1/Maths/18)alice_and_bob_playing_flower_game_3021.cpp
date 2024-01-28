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
