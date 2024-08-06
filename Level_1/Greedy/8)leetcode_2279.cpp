Solution 1-:
Steps-:
1)using min heap where difference bw -> capacity[i]-rocks[i] will be filled first.
2)min heap will be of pair -> {diff,index}.
3)filled the rocks[i] those having less differnce and additionalRocks will be substract accordingly.



Code-:
int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n=capacity.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,
                       greater<pair<int,int>>>pq;
        for(int i=0;i<n;i++)
        {
            int diff=capacity[i]-rocks[i];
            pq.push({diff,i});
        }

        while(pq.empty()==false)
        {
            int needed=pq.top().first;
            int index=pq.top().second;
            pq.pop();
            if(additionalRocks>=needed)
            {
               additionalRocks-=needed;
               rocks[index]+=needed;
            }
            else
            break;
        }

        int count=0;
        for(int i=0;i<n;i++)
        {
            if(rocks[i]==capacity[i])
            count++;
        }
        return count;
}


Solution 2-:  Using sorting.
Steps-:
1)Here we make left array which store the required rocks[i] to match capacity[i].
2)Now i sort the left array.
3)Now we run the loop on sorted array and substract the additionalRocks accordingly.


Code-:
int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n=capacity.size();
        vector<int>left(n);
        for(int i=0;i<n;i++)
        {
            left[i]=capacity[i]-rocks[i];
        }

        sort(left.begin(),left.end());
        int i;
        for(i=0;i<n;i++)
        {
            if(additionalRocks>=left[i])
            {
                additionalRocks-=left[i];
            }
            else
            break;
        }
        return i;
}
