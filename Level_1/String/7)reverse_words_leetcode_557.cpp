s="God Ding"

1) Res="" ans=""
2) reverse the given string  s="gind dog"
3) store the string upto gap in it (res=gind)
4) when we see gap (ans=res+' '+ans)  ans=gind and res=" ";
5) same repeat
6) at last when loop finish (ans=res+' '+ans) 
7) decrease the size of string ans by 1 from end


Code-> O(n) time and O(n) space
string reverseWords(string s) {
        reverse(s.begin(),s.end());
        
        string ans="";
        string res="";
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==' ')
            {
               ans=res+' '+ans;
               res="";
            }
            else
            {
                res+=s[i];
            }
        }
        ans=res+' '+ans;
        ans.pop_back();
        return ans;
    }


Solution 2  in js
var reverseWords = function(s) {
   let res=""
   let ans=""
   for(let i=0;i<s.length;i++)
   {
       if(s[i]==' ')
       {
          ans=ans+' '+res;
          res="";
       }
       else
       {
           res=s[i]+res;
       }
   }
   ans=ans+' '+res;
   ans=ans.slice(1);
   return ans; 
};
