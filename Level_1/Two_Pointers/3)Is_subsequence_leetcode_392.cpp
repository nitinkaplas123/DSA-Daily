Solution -1 

Code-:
bool isSubsequence(string s, string t) {
        int n=s.length();
        int m=t.length();

        int i=0;
        int j=0;
        while(i<n and j<m)
        {
            if(s[i]==t[j])
            {
                i++;
                j++;
            }
            else 
            j++;
        }
        return (i==n)?1:0;
    }


Js-:
var isSubsequence = function(s, t) {
    let n=s.length;
    let m=t.length

    let i=0;
    let j=0;
    while(i<n && j<m)
    {
        if(s[i]==t[j])
        {
            i++;
            j++;
        }
        else
        j++;
    }
    return (i==n)?1:0;
};