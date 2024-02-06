Solution 1-:
Code-: Time->O(N)

bool rotateString(string s, string goal) {
        for(int i=0;i<s.length();i++)
        {
           if(s==goal) return true;
           char ch=s.back();
           s.pop_back();
           s=ch+s;
        }
        return (s==goal);
   }