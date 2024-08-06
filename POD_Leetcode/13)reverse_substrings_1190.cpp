Solution 1-:
Steps-:
1)when we see opening bracket it means we have to skip the previous charcters for reverse.
2)So for that whenever we see opening bracket we push res length into vector v and when we see closing 
  bracket we reverse the res from start+val.

Time ->O(N^2)  beacause we use reverse function
Code-:
string reverseParentheses(string s) {
       string res="";
       vector<int>v;
       for(int i=0;i<s.length();i++)
       {
          if(s[i]=='(')
          v.push_back(res.length());
          else if(s[i]==')')
          {
             int val=v.back();
             v.pop_back();
             reverse(res.begin()+val,res.end());
          }
          else
          res+=s[i];
       }
       return res;
}



Solution 2-:
Steps-:
Go from left to right and right to left.
0)firstly we store opening closing pair index into vector door using stack.
1)When we see opening bracket go to its closing bracket and change its direction if we see closing 
  bracket then go to its opening bracket and change its direction.
2)if we see charcter add into ans string.


Time ->O(N)
Code-:
string reverseParentheses(string s) 
{
       int n=s.length();
       stack<int>openBracketIdx;
       vector<int>door(n);

       for(int i=0;i<n;i++)
       {
         if(s[i]=='(')
         openBracketIdx.push(i);
         else if(s[i]==')')
         {
            int idx=openBracketIdx.top();
            openBracketIdx.pop();
            door[idx]=i;
            door[i]=idx;
         }
       }

     

       string ans="";
       int flag=1;
       for(int i=0;i<n;i+=flag)
       {
           if(s[i]=='(' || s[i]==')')
           {
              i=door[i];
              flag=-flag;
           }
           else
           ans+=s[i];
       }
       return ans;
}