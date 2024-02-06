C++ -:
Code:
char nonrepeatingCharacter(string S)
{
       int count[26]={0};
       for(int i=0;i<S.length();i++)
       {
           count[S[i]-'a']++;
       }
       
       for(int i=0;i<S.length();i++)
       {
           if(count[S[i]-'a']==1)
           return S[i];
       }
       return '$';
}





Js Code-:
nonrepeatingCharacter(s)
{
   let count=new Array(256)
   count.fill(0)
   for(let i=0;i<s.length;i++)
   {
       count[s.charCodeAt(i)-97]++
   }
   
   for(let i=0;i<s.length;i++)
   {
       if(count[s.charCodeAt(i)-97]==1)
       return s[i]
   }
   return '$'
}