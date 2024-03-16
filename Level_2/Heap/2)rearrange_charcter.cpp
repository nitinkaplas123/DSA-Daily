Solution 1-:
Steps-:
1)firstly we create hashmap and store the freq of each character.
2)create a max heap which give me first max freq of that charcter.
3)now make a string res of size (s.size()).
4)put the charcter freq times into res string (ont step ahead).
5)At last if we find res[i]==res[i+1] which means we cannot rearrange the string.


Code-: Time ->O(Nlog(K))
string reorganizeString(string s) {
        unordered_map<char,int>m;
        for(int i=0;i<s.length();i++)
        {
            m[s[i]]++;
        }

        priority_queue<pair<int,char>>pq;
        for(auto x:m)
        {
            pq.push({x.second,x.first});
        }

        string res(s.size(),' ');
         
        int index=0;
        while(pq.empty()==false)
        {
            auto x=pq.top();
            pq.pop();
            int freq=x.first;
            char ch=x.second;
         
            while(freq--)
            {
              if(index>=s.size())
              index=1;

              res[index]=ch;
              index+=2;
            }
        }

        for(int i=0;i<res.size()-1;i++)
        {
            if(res[i]==res[i+1]) return "";
        }
        return res;
    }
