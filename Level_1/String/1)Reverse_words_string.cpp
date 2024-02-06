Solution 1
Steps-:
1)Make a stack to put the string in it.
2)After putting all values in stack extract one by one and add into new string.
3)Take care of space here.

Time complexity - O(N)
Space - O(N)

Code-:
string reverseWords(string s) {
        stack<string>st;
        string str="";
        for(int i=0;i<s.length();i++)
        {
          if(s[i]==' ' and str!="")
          {
            st.push(str);
            str="";
          }
          else if(s[i]==' ')
          continue;
          else
          str+=s[i];
        }
        if(str!="")
        st.push(str);

        string ans="";
        while(st.empty()==false)
        {
           ans+=st.top();
           st.pop();
           if(st.empty()==false)
           ans+=" ";
        }
        return ans;
    }


Solution -2
Steps-:
1) Using idea first reverse string words like ( hello kaplas)=> (olleh  salpak)
2) Then reverse whole string (olleh  salpak)  => (kaplas hello)
3) If we have extra gap then remove by iterating from end of string and using substr
   we can extract it.


Code-
string reverseWords(string s) {
        string str="";
        string ans="";
        for(int i=0;i<s.length();i++)
        {
          if(s[i]==' ' and str!="")
          {
            reverse(str.begin(),str.end());
            ans+=str;
            ans+=" ";
            str="";
          }
          else if(s[i]==' ')
          continue;
          else
          str+=s[i];
        }
       
        if(str!="")
        {
          reverse(str.begin(),str.end());
          ans+=str;
        }
        
        int len=ans.length()-1;
        int i=0;
        while(ans[len-i]==' ')
        {
           i++;
        }
        ans=ans.substr(0,len-i+1);
        reverse(ans.begin(),ans.end());
        return ans;
    }


Time Complexity -> O(2N)
Space => O(1)



Solution -3

Steps-:
1)Using two pointer approach where we fix i index at starting of word and j at end of word.
2)Now using substr (i,j-i) (start,length) we add into res.
3) For reversing we use -:
 
 for eg.   Hello Kaplas
 1)res=""
 sub= hello.
 if(res=="")
 res=sub   (res=Hello)

 2)sub=Kaplas
 res=sub+' '+res.

 res=kaplas Hello


Code-:
string reverseWords(string s) {
       int n=s.length();
       int i=0;
       int j=0;
       string res="";
       while(i<n)
       {
         while(i<n and s[i]==' ')
         {
            i++;
         }

         if(i>=n) break;

         j=i+1;
         while(j<n and s[j]!=' ')
         {
           j++;
         }

         string sub=s.substr(i,j-i);
         if(res=="")
         res=sub;
         else
         res=sub+' '+res;
         i=j+1;
       }
       return res;
    }

Time complexity - O(N)
Space - O(1)


Solution 4-:

Steps-:
1)Same approach as we do in stack just here we replaced stack.
Code-:
string reverseWords(string s) {
        string str="";
        string ans="";

        for(int i=0;i<s.length();i++)
        {
            if(s[i]==' ' and str!="")
            {
               if(ans!="")
               ans=str+' '+ans;
               else
               ans=str;
               str="";
            }
            else if(s[i]!=' ')
            str+=s[i];
            else
            continue;
        }
        if(str!="" and ans!="")
        ans=str+' '+ans;
        else if(str!="")
        ans=str;
        return ans;
      }


