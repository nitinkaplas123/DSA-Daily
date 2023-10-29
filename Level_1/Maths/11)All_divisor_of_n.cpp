Solution 1-:
Steps-:
Notes-:
1)If n==1 then o/p ->1 only
2)for that we use n/i!=i only then we have to print its n/i.

Code-: Time->O(sqrt(n)) Space->O(sqrt(N))

 void print_divisors(int n) {
        vector<int>v;
        for(int i=1;i*i<=n;i++)
        {
            if(n%i==0)
            {
                cout<<i<<" ";
                if(n/i!=i)
                v.push_back(n/i);
            }
        }
        for(int i=v.size()-1;i>=0;i--)
        {
            cout<<v[i]<<" ";
        }
    }