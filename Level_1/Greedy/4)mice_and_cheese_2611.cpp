Solution 1-:
Steps-:
1)you want max sum from v1 and v2 array.
2)you want exact k elements from v1 and n-k from v2.
3)diff = (v1[i]-v2[i])
4)if diff is largest +ve value then it means v1[i] value is much greater than compare to v2[i] 
  so in this case we give priority to largest +ve value in v1[i] compared to v2[i].
5)We make maxheap for that in max heap will be based upon diff value and add corresponding index of it.

Step1-:
1)make maxheap and build acc. to the differnce.
Step2-:
1)add top k elements from v1 vector using maxheap differnce
2)add the index value which is taken from v1[i] into set so that we know that 
  that particular index will not taken now for the v2[i].
Step3 -:
1)now add all the values from v2[i] firstly check from set if that particular index is not present 
  in set.


Code-:
int miceAndCheese(vector<int>& v1, vector<int>& v2, int k) {
       int n=v1.size();
       priority_queue<pair<int,int>>pq;
       for(int i=0;i<n;i++)
       {
         int diff=(v1[i]-v2[i]);
         pq.push({diff,i});
       }
       
       unordered_set<int>s;
       int ans=0;
       while(pq.empty()==false and k--)
       {
         int index=pq.top().second;
         int val=v1[index];
         pq.pop();
         s.insert(index);
         ans+=val;
       }

       for(int i=0;i<n;i++)
       {
         if(s.find(i)==s.end())
         ans+=v2[i];
       }
       return ans;
}


Solution 2-:
Steps-:
1)without set.
2)At step2 i am add v1[index] and substract v2[index].
3)At step3 i am adding all v2[index]
4)while(k--) because in question we are given the value of k=0,k<n

Code-:
int miceAndCheese(vector<int>& v1, vector<int>& v2, int k) {
       int n=v1.size();
       priority_queue<pair<int,int>>pq;
       for(int i=0;i<n;i++)
       {
         int diff=(v1[i]-v2[i]);
         pq.push({diff,i});
       }
       
       int ans=0;
       while(k--)
       {
         int index=pq.top().second;
         int val=v1[index];
         pq.pop();
         ans+=val;
         ans-=v2[index];
       }

       for(int i=0;i<n;i++)
       {
         ans+=v2[i];
       }
       return ans;
    }