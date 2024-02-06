Solution 1-:
Steps-:
1)Store all values in hashmap.
2)Now if the curr_value>next_value then add the curr_value in ans else subtract the curr_value.

Code-:
int romanToInt(string s) {
        unordered_map<char,int>m;
        m.insert({'I',1});
        m.insert({'V',5});
        m.insert({'X',10});
        m.insert({'L',50});
        m.insert({'C',100});
        m.insert({'D',500});
        m.insert({'M',1000});

        int ans=0;
        
        for(int i=0;i<s.length()-1;i++)
        {
            if(m[s[i]]>=m[s[i+1]])
            ans+=m[s[i]];
            else
            ans-=m[s[i]];
        }
        return ans+m[s[s.length()-1]];
    }