Refernce-> Notebook 1 Page no. -> 48

Solution 1-:
Steps-:
1)Intially we have temp variable where we put the string.
  temp="";
2)There is 2 cases -:
  1)if hasDuplicate(arr[index],temp)
  excluded 
  2)if there is no duplicate 
  max(included,excluded)


Code-:
bool duplicate(string s1,string s2)
{
        int count[26]={0};

        for(int i=0;i<s1.length();i++)
        {
            count[s1[i]-'a']++;
        }

        for(int i=0;i<s2.length();i++)
        {
            count[s2[i]-'a']++;
        }

        for(int i=0;i<26;i++)
        {
            if(count[i]>1)
            return true;
        }
        return false;
}

int helper(vector<string>arr,int index,int n,string temp,int &ans)
    {
        if(index==n)
        return temp.length();
        
        int exclude=0;
        int include=0;
       
        if(duplicate(arr[index],temp))
        return helper(arr,index+1,n,temp,ans);
        else
        {
           include=helper(arr,index+1,n,temp+arr[index],ans);
           exclude=helper(arr,index+1,n,temp,ans);
           ans=max(include,exclude);
           return ans;
        }
  }

    int maxLength(vector<string>& arr) {
        int n=arr.size();
        int index=0;
        int ans=0;
        string temp="";
        helper(arr,index,n,temp,ans);
        return ans;
    }

Solution 2-:
Steps-:
1)Using memoizations.


Code-:
bool duplicate(string s1,string s2)
{
        int count[26]={0};

        for(int i=0;i<s1.length();i++)
        {
            count[s1[i]-'a']++;
        }

        for(int i=0;i<s2.length();i++)
        {
            count[s2[i]-'a']++;
        }

        for(int i=0;i<26;i++)
        {
            if(count[i]>1)
            return true;
        }
        return false;
}

unordered_map<string,int>m;
int helper(vector<string>arr,int index,int n,string temp,int &ans)
{
        if(index==n)
        return temp.length();
        if(m.find(temp)!=m.end())
        {
            return m[temp];
        }
        
        int exclude=0;
        int include=0;
        //duplicate check
        if(duplicate(arr[index],temp))
        exclude= helper(arr,index+1,n,temp,ans);
        else
        {
           include=helper(arr,index+1,n,temp+arr[index],ans);
           exclude=helper(arr,index+1,n,temp,ans);
        }
        ans=max(include,exclude);
        return m[temp]=ans;
}

int maxLength(vector<string>& arr) {
        int n=arr.size();
        int index=0;
        int ans=0;
        string temp="";
        helper(arr,index,n,temp,ans);
        return ans;
}