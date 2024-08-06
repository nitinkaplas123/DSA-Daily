
Solution 1-:
Steps-:
1)Using map.


Code-: Time -> O(N+M) Space->O(N+M)log(N+M)
vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int>v;
        map<int,int>m;
        for(int i=0;i<arr1.size();i++)
        {
            m[arr1[i]]++;
        }

        for(int i=0;i<arr2.size();i++)
        {
            int val=arr2[i];
            int count=m[val];
            for(int j=0;j<count;j++)
            {
                v.push_back(val);
            }
            m.erase(val);
        }
        for(auto x:m)
        {
            int val=x.first;
            int count=x.second;
            for(int j=0;j<count;j++)
            {
                v.push_back(val);
            }
        }
        return v;
}


Solution 2-:
Steps-:
1)using count array 

Code-: Time->O(N+M) Space->O(1000) which is constant 
vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int count[1001]={0};
        for(int i=0;i<arr1.size();i++)
        {
            count[arr1[i]]++;
        }
        
        int pos=0;
        for(int i=0;i<arr2.size();i++)
        {
            while(count[arr2[i]]--)
            {
               arr1[pos++]=arr2[i];
            }
        }

        for(int i=0;i<=1000;i++)
        {
            if(count[i]>0)
            {
                while(count[i]--)
                {
                    arr1[pos++]=i;
                }
            }
        }
        return arr1;
    }