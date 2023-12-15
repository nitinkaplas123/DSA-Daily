Solution 1-:
Steps-:
1)here we use hashset.
2)we have to return the destination and as we know destination is the second value in pair of vector.
3)So we add all the first value of vector into hashset.
4)Now check if destination is present in hashset if yes it means its not the final destination 
  if not present means this is our answer.


Code-: Time->O(N) Space->O(N)
string destCity(vector<vector<string>>& paths) {
        unordered_set<string>s;
        int n=paths.size();
        for(int i=0;i<n;i++)
        {
            s.insert(paths[i][0]);
        }

        for(int i=0;i<n;i++)
        {
            string str=paths[i][1];
            if(s.find(str)==s.end())
            return str;
        }
        return "";
    }


In js -:
var destCity = function(paths) {
    let n=paths.length;
    let set=new Set();
    for(let i=0;i<n;i++)
    {
        set.add(paths[i][0]);
    }

    for(let i=0;i<n;i++)
    {
        if(set.has(paths[i][1]))
        continue;
        else
        return paths[i][1];
    }
    return "";
};