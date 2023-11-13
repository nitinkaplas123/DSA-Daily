Solution 1-:
Steps-:
1)check from last if this digit is odd 

Code-: Time->O(N)
string largestOddNumber(string num) {
        int n=num.length();
        int i;
        for(i=n-1;i>=0;i--)
        {
            int val=(num[i]-'0');
            if(val%2!=0)
            break;
        }
        return num.substr(0,i+1);
    }