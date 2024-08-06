Code-:

long long ExtractNumber(string S)
    { 
       long long ans = -1;
       string str = "";
       int i = 0;
    
       while (i < S.length())
       {
         if (isdigit(S[i]) && S[i] != '9') 
         {
            str = "";  
            while (i < S.length() && isdigit(S[i]) && S[i] != '9') 
            {
                str += S[i];
                i++;
            }
            
            if (!str.empty() and S[i]!='9')
            {
                long long val = stoll(str);
                ans=max(ans,val);
            }
         } 
         else if(i<S.length() and isdigit(S[i]) and S[i]=='9')
         {
            while (i < S.length() && isdigit(S[i])) 
            {
                i++;
            }
         }
         else
         i++; 
    }
    return ans;
    }