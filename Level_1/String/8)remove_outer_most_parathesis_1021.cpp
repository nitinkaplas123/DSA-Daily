Solution 1-:
Steps-:
1)using simple visualise

Code-: Time->O(N)
string removeOuterParentheses(string s) {
        int n=s.length();
        string ans="";
        string curr="";
        int i=0;
        int count=0;
        while(i<n)
        {
           if(s[i]=='(' and count==0)
           count++;
           else if(s[i]=='(')
           {
               count++;
               curr+=s[i];
           }
           else 
           {
               count--;
               if(count!=0)
               curr+=s[i];
               else
               {
                  ans+=curr;
                  curr="";
               }
           }
           i++;
        }
        return ans;
    }


Solution 2-:
Steps-:
1)if count>0 then add res+='('
2)if count>1 then add res+=')'


Code-: Time->O(N)
string removeOuterParentheses(string s) {
       int count=0;
       string res="";
       for(int i=0;i<s.length();i++)
       {
          if(s[i]=='(')
          {
              if(count>0)
              res+=s[i];
              count++;
          }
          else
          {
              if(count>1)
              res+=s[i];
              count--;
          }
       }
       return res;
    }