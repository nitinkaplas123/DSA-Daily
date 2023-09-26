Solution 1-:
Steps-:
1)Here we have to expand whole string.
  eg. ha22
  1. str=ha 
  2. here we have 2 digit which means we have to repeat the string digit-1 times
     str= ha ha
  3. here again we have 2 as a digit repeat the whole string digit-1 times.
     str=haha haha

    final string =>hahahaha
2)we expand the whole string now k=5 so return str[k-1]  which is h as o/p.


Note-:
but for big numbers  this approach gives memory limit execeded error.

Code-:  not recommended this sol.

string decodeAtIndex(string s, int k) {
        string ans="";
        string curr="";
        for(int i=0;i<s.length();i++)
        {
            if(s[i]>='a' && s[i]<='z')
            {
                ans+=s[i];
                curr+=s[i];
            }
            else 
            {
                int val=s[i]-'0';
                for(int j=0;j<val-1;j++)
                {
                    ans+=curr;
                }
                curr=ans;
            }
        }
        cout<<ans<<endl;
        string res;
        res+=ans[k-1];
        return res;
    }



Solution 2-:
Steps-:
1)Here we donot expand the string just traverse the given string from back.
2)First a fall we have to find the size of string.
  leetleetcode leetleetcode leetleetcode
  size=36
3)Then traverse string from back 

  Case 1-:
  If we got a digit then we reduced the string by size =(size/digit)
  eg. s = "leet2code3", k = 10

  Case 2-:
  if k%size==0 
  which means we reach at our answer
  return charcter at that place.

  Case 3-:
  if current element is char then we decreases by 1



Code-:  Time->O(N) where n is length of character
string decodeAtIndex(string s, int k) {
        int n=s.length();
        long size=0;
        for(int i=0;i<n;i++)
        {
           int val=s[i]-'0';
           if(s[i]>='a' and s[i]<='z')
           size++;
           else
           size=size*val;
        }
        
        for(int i=n-1;i>=0;i--)
        {
            string str;
            k=k%size;
            int val=s[i]-'0';
            if(isdigit(s[i]))
            size=size/val;
            else if(k==0)
            {
                str="";
                str+=s[i];
                return str;
            }
            else
            size--;
        }
        return "";
    }

