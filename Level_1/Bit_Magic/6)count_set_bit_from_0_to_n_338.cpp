Solution 1-:
Steps-:
1) Normal ways as we do previous.

Code-: Time->O(nk) where k is the no. of set bit 
vector<int> countBits(int n) {
        vector<int>v;
        v.push_back(0);
        for(int i=1;i<=n;i++)
        {
            int val=i;
            int count=0;
            while(val!=0)
            {
                val=(val & (val-1));
                count++;
            }
            v.push_back(count);
        }
        return v;
    }


Solution 2-:

observation-:
1 -> 001 
2 -> 010
3 -> 011
4 -> 100
5 -> 101
6 -> 110
7 -> 111
8 -> 1000
9 -> 1001
10 ->1010

Steps-:
1)if we clearly see for every even number -> v[i]=v[i/2]
2)for odd number -> v[i]=v[i/2]+1

Code-: Time->O(N)
vector<int> countBits(int n) {
        vector<int>v(n+1,0);
        for(int i=1;i<=n;i++)
        {
             //even
             if(i%2==0)
             v[i]=v[i/2];
             else
             //odd
             v[i]=v[i/2]+1;
        }
        return v;
}


