Solution 1-:
Steps-:
1)using visualising 
2)here we make a back string which we compare with given substring s 
There is 2 cases -:
1)when the whole back string is matching then flag=true and 
  i=where we left 
  j=0

2)when the back string is not match here we append the charcter into back string which is just after it.
  back+=s[m] 
  and here i=back.length()

3)if j==m which means its matching 
  flag=true
4)else
  flag=false.


Code-: Time->O(N^2)
bool repeatedSubstringPattern(string s) {
        int n=s.length();
        int i=1;
        string back="";
        back+=s[0];
        bool flag=false;

        while(i<n)
        {
          int j=0;
          int m=back.length();
          while(i<n and j<m)
          {
              if(s[i]!=back[j]) 
              {
                  back+=s[m];
                  i=back.length();
                  flag=false;
                  break;
              }
              else
              {
                  i++;
                  j++;
              }
          }
          if(j==m)
          flag=true; 
          else
          flag=false;
        }
        return flag;
}



Solution 2-:

eg. s="ababab"
1) pat="a"
   now we have to add pat n times which is make a length of s 
   pat -> 6 times.
   pat-> aaaaaa

   which is not matching.

2) pat="ab"
   now pat-> 3 times.
   pat-> ababab 

   here pat==s.
   which means return true.

3) pat="aba"
   nw pat-> 2 times       here times ->n/i.
   pat-> abaaba

   not matching.


Code-: Time-> O(N*sqrt(N))
bool repeatedSubstringPattern(string s) {
        int n=s.length();
        
        for(int i=n/2;i>=1;i--)   // its n/2
        {
            if(n%i==0)            // here its divisor of N  is 2*sqrt(N) 
            {
              string pat=s.substr(0,i);
              int times=n/i;
              
              string str="";
              while(times--)
              {
                  str+=pat;
              }
              if(str==s) return true;
            }
        }
        return false;
    }


✔explaination of running loop from n/2 : 😎

For those who are wondering why to choose
option-1) "for(int i = len/2; i>=1; i--)"
and not
option-2) "for(int i = 1; i<=len/2; i++)"

Lets take a small example to find which is better :
s = "abcabcabcabc"

If we chose option-1, we can find "abcabc" is the substring which when repeated "twice" gives the string s.

If we chose option-2, we can find "abc" is the substring which when repeated "4 times" gives the string s.

So, obviously option-1 is better as we are looking for the largest repeated substring first to minimize the time.


Solution 3-:
Steps-:
1) here same concept 
2) compare ->
   s.substr(0,n-i)== s.substr(i)



Eg. s="ababab"

1) i=3
   s1=s.substr(0,n-i)

   s1=aba 

   s2=s.substr(i)
   s2=bab

   s1!=s2

2) i=2
   s1=abab
   s2=abab

   s1==s2
   return true

3) i=1
   s1=ababa
   s2=babab

   s1!=s2
   return false


Code-: Time->O(2*Sqrt(N))
bool repeatedSubstringPattern(string s) {
        int n=s.length();
        
        for(int i=n/2;i>=1;i--)
        {
            if(n%i==0)
            {
               if(s.substr(0,n-i)==s.substr(i)) return true;
            }
        }
        return false;
}