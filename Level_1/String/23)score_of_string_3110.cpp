Solution 1-:
Steps-:
1)Simply do the abs difference 

Code-:
int scoreOfString(string s) {
        int sum=0;
        for(int i=1;i<s.length();i++)
        {
            sum+=abs(s[i]-s[i-1]);
        }
        return sum;
    }


Java -:
 public int scoreOfString(String s) {
        int sum=0;
        for(int i=1;i<s.length();i++)
        {
            sum+=Math.abs(s.charAt(i)-s.charAt(i-1));
        }
        return sum;
}