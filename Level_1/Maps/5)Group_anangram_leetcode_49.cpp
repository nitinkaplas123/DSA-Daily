Solution -1  Time Complexity ->O(N *k(logk))    Space ->O(N)
             here N is for the whole traversal of string 
             K(log(k)) is for sort the string 

Steps-:
1)Make a hashmap for unordered_map<string,vector<string>>m;
2)Sort the string before sort save the original string.
3)Now m[sort_string].push_back(original_string)
4)At last we push it into ans vector of vector


Code-:
vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>m;
        for(int i=0;i<strs.size();i++)
        {
            string s=strs[i];
            string s1=s;
            sort(s1.begin(),s1.end());
            m[s1].push_back(s);
        }

        vector<vector<string>>ans;
        for(auto x:m)
        {
            ans.push_back(x.second);
        }
        return ans;
    }


Js Code-:

var groupAnagrams = function(strs) {
    let m=new Map()
    strs.forEach((word)=>{
       
        let sorted_str=word.split("").sort().join("")
        if(m.has(sorted_str))
        m.get(sorted_str).push(word)
        else
        m.set(sorted_str,[word])
    })
    
    let res=[]
    m.forEach((value,key)=>{
        res.push(value)
    })
    return res
};