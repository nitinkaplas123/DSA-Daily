Solution -1
Steps-:
1)Make a two stack st1,st2.
2)St1 is for opening brackets and st2 is for closing brackets.
3)When we have opening add into st1 and when we get closing then -:
  Case -1
  If we have st1.size()>0 then st1.pop to neutralise the opening closing.
  Case -2
  else add the closing bracket into st2.
4)At last we return the len of st1 + len of st2.
  because this is opening closing brackets which is not neutralised.

Code-:
nt minAddToMakeValid(string s) {
        stack<char>st1;
        stack<char>st2;
        for(int i=0;i<s.length();i++)
        {
          if(s[i]=='(')
          st1.push(s[i]);
          else
          {
            if(st1.empty()==false)
            st1.pop();
            
            else
            st2.push(s[i]);
          }
        }
        return st1.size() + st2.size();
    }

    Time Complexity - O(N)
    Auxiliary space - O(2*N) =>O(N)


Solution -2 
Steps-:
Whenever we get open bracket we will increase count by 1 
and when we get close bracket we will decrease count by 1.
But If our count becomes less than 0 than we have to add open 
bracket before current position so just absolute value of count 
and make count 0. Now at last we will add count to ans as we have 
to close all opened bracket.


Code-:
nt minAddToMakeValid(string s) {
        int c=0;
        int ans=0;
        for(int i=0;i<s.length();i++)
        {
          if(s[i]=='(')
          c++;
          else
          {
            c--;
            if(c<0)
            {
               ans++;
               c=0;
            }
          }
        }
        return ans+abs(c);
    }


    Time Complexity - O(N)
    Auxiliary space - O(1)