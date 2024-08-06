Solution 1-:
Steps-:
1)Store the frequency of char in hashmap.
2)Now check if charcter is at odd position in english alphabet and that charcter 
  frequency is odd -> ans++;
3)Now check if charcter is at even position in english alphabet and that charcter 
  frequency is even -> ans++;
4)At last return ans;


Code-:
string oddEven(string s) {
        unordered_map<char,int>m;
        for(int i=0;i<s.length();i++)
        {
            m[s[i]]++;
        }
        
        int ans=0;
        for(auto x:m)
        {
            char ch=x.first;
            if((ch-'a')%2!=0 and m[ch]%2==0)
            ans++;
            else if((ch-'a')%2==0 and m[ch]%2!=0)
            ans++;
            else
            continue;
        }
        return (ans%2==0)?"EVEN":"ODD";
    }