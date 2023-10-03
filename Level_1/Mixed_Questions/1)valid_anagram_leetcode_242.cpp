Solution -1
Steps-:
1)Make two hashmap m1 and m2
2)Increment the freq in both m1 and m2.
3)At last just compare  return (m1==m2)

Code-: Time->O(N)  Space ->O(N)
 bool isAnagram(string s, string t) {
        int n1=s.length();
        int n2=t.length();
        if(n1!=n2) return false;

        unordered_map<int,int>m1;
        unordered_map<int,int>m2;
        for(int i=0;i<n1;i++) m1[s[i]-'a']++;

        for(int i=0;i<n1;i++) m2[t[i]-'a']++;

        return (m1==m2);
    }


Solution -2

Steps-:
1)Just replace the map with count array of 26 size bcz maxx character is size 26.
2)For s increment the count array.
3)For t decrement the count array.
4)At last if in count array any character have any freq greater than 0 return false.


Code-:  Time->O(N)  Space->O(1)

bool isAnagram(string s, string t) {
        int n1=s.length();
        int n2=t.length();
        if(n1!=n2) return false;
        
        int count[26]={0};
        
        for(int i=0;i<n1;i++) count[s[i]-'a']++;

        for(int i=0;i<n1;i++) count[t[i]-'a']--;

        for(int i=0;i<26;i++)
        {
            if(count[i]!=0)
            return false;
        }
        return true;
    }


Js Code-:
var isAnagram = function(s, t) {
        let n1=s.length;
        let n2=t.length;
        if(n1!=n2) return false;
        
        let count=new Array(26).fill(0)
        
        for(let i=0;i<n1;i++) count[s.charCodeAt(i)-'a'.charCodeAt(0)]++;

        for(let i=0;i<n1;i++) count[t.charCodeAt(i)-'a'.charCodeAt(0)]--;

        for(let i=0;i<26;i++)
        {
            if(count[i]!=0)
            return false;
        }
        return true;
};