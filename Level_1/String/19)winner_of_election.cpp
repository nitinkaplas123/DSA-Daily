Solution 1-:
Steps-:
1)here we first make a hashmap where we store key and value as freq.
2)now we make a vector of pair 
3)Now we have to sort the vector according to freq and if freq equal then acc to lexigraphic string.
4)return the first vector elements.

Code-: Time->O(Nlog(N)) Space=>O(N)
static bool comp(pair<string,int>&a,pair<string,int>&b)
    {
        if(a.second==b.second)
        return a.first<b.first;
        else
        return a.second>b.second;
    }
    vector<string> winner(string arr[],int n)
    {
        unordered_map<string,int>m;
        for(int i=0;i<n;i++)
        {
            m[arr[i]]++;
        }
        
        vector<pair<string,int>>v;
        for(auto x:m)
        {
            v.push_back({x.first,x.second});
        }
        
        sort(v.begin(),v.end(),comp);
        return {v[0].first,to_string(v[0].second)};
    }



Solution 2-:
Steps-:
1)Just compare with count and str.


Code-: Time->O(N) Space->O(N)
vector<string> winner(string arr[],int n)
{
       unordered_map<string,int>m;
       for(int i=0;i<n;i++)
       {
           m[arr[i]]++;
       }
       
       int count=0;
       string str;
       for(auto x:m)
       {
           if(x.second>count)
           {
               count=x.second;
               str=x.first;
           }
           else if(count==x.second and str.compare(x.first)>0)
           str=x.first;
           else
           continue;
       }
       return {str,to_string(count)};
}