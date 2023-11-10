Solution 1-:
Steps-:
1)We have to sort the intervals  vector according to 1 values.
2)There are 2 cases.
Case 1-:
1)[1,3] [3,6]
  
  ans[1,3]

  i=1 
  if(intervals[i][0]<=v.back()[1] and intervals[i][1]>v.back()[1])
  v.back()[1]=intervals[i][1];

  ans[1,6]


Case 2-:
2) [1,3] [5,6]
   
   ans[1,3]

   i=1
   if(intervals[i][0]>v.back()[1])
   v.push_back(intervals[i])

   ans [1,3],[5,6]



Code-: Time->O(nLogn) Space->O(1)
vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<vector<int>>v;
        sort(intervals.begin(),intervals.end());

        v.push_back(intervals[0]);
        for(int i=1;i<n;i++)
        {
           if(intervals[i][0]<=v.back()[1] and intervals[i][1]>v.back()[1])
           v.back()[1]=intervals[i][1];
           else if(intervals[i][0]>v.back()[1])
           v.push_back(intervals[i]);
           else
           continue;
        }
        return v;
    }