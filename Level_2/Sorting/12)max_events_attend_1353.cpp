Solution 1-:
Steps-:
1)Sort the events vector using end time.
2)Now we find the maxx elements because we store the 1 to maxx values into set as days.(pool of days we can use)
3)Now we traverse the loop we have start=events[i][0] and end=events[i][1].
4)We find the min value in loop from start to end to select the day using lower_bound where lower_bound gives
  the that element which we search or just greater of it.
5)If that value is not present in pool or value is greater than end time then continue the loop
6) else count++ and erase the value from the pool set.
7)Return the count


This is the example why we sort according to end time 
[[1,2],[1,2],[3,3],[1,5],[1,5]]


Code-: Time->O(nlogn)  Space ->O(N)
static bool comp(vector<int>&a,vector<int>&b)
{
        if(a[1]==b[1])
        return a[0]<b[0];
        return a[1]<b[1];
 }

    int maxEvents(vector<vector<int>>& events) {
       sort(events.begin(),events.end(),comp);
       
       int maxx=INT_MIN;
       for(int i=0;i<events.size();i++)
       {
           maxx=max(maxx,max(events[i][0],events[i][1]));
       }

       set<int>s;
       for(int i=1;i<=maxx;i++)
       {
           s.insert(i);
       }

       int count=0;
       for(int i=0;i<events.size();i++)
       {
          int start=events[i][0];
          int end=events[i][1];

          auto it=s.lower_bound(start);
          if(it==s.end() || *it>end)
          continue;
          else
          {
              count++;
              s.erase(it);
          }
       }
       return count;
    }