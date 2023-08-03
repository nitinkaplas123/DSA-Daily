Solution -1

Steps-:
1)Make a stack of string.
2)Make a variable as curr_string where we store character after opening and closing bracket.
3)Make a varible as curr_num where we store the digit before string.
Case-1 
When we encounter with opening bracket we push the string and num into stack and make curr_num,
  curr_string as empty.

Case-2
When we encounter with closing bracket we pop the top of stack as number and next top as string.
Here means we complete the small decode so store the string here as-:
curr_string=prev_string+curr_string*prev_num;

Case-3
If we get as a digit then store into curr_num;

Case-4
If we get as a charcter then store into curr_string.



Code-:
 string helper(string curr_string,string prev_num)
    {
      int val=stoi(prev_num);
      string res="";
      for(int i=0;i<val;i++)
      {
        res+=curr_string;
      }
      return res;
    }
    string decodeString(string s) {
        string curr_num="0";
        stack<string>st;
        string curr_string="";
        for(int i=0;i<s.length();i++)
        {
          if(s[i]=='[')
          {
             st.push(curr_string);
             st.push(curr_num);
             curr_num="0";
             curr_string="";
          }
          else if(s[i]==']')
          {
             string prev_num=st.top();
             st.pop();
             string prev_string=st.top();
             st.pop();

             curr_string=prev_string+helper(curr_string,prev_num);
          }
          else if(isdigit(s[i]))
          {
            curr_num+=s[i];
          }
          else
          {
            curr_string+=s[i];
          }
        }
        return curr_string;
    }
