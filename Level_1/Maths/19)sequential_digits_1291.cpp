Solution 1-:
Steps-:
1)Check every number from low to high.
2)using stack we put all the digits of a number and compare with it.

Code-: Time->O(N^2)
 bool helper(long long n)
    {
        stack<long long>st;
        while(n!=0)
        {
            long long val=n%10;
            st.push(val);
            n=n/10;
        }

        while(st.size()>1)
        {
            long long val1=st.top();
            st.pop();
            long long val2=st.top();
            st.pop();
            if(val1+1!=val2)
            return false;
            else
            st.push(val2);
        }
        return true;
    }
    vector<int> sequentialDigits(int low, int high) {
        vector<int>ans;
        for(int i=low;i<=high;i++)
        {
            if(helper(i))
            ans.push_back(i);
        }
        return ans;
    }



Solution 2-:
Steps-:
1)here we are using queue 
2)firstly we put all the numbers from 1 to 8 
  why not 9 because in question its mention number should be greater than 10.
  so we do not add because later its make -> 9,10 -> 910 this is not valid number.
Three Cases-:
Case1-:
we take the top element from queue and check its in range of low and high.
if yes-:
ans.push_back(val);

Case 2-:
if val>high
here all elements which are in queue are not in range 
so we break the loop.

Case3 -:
if(last_digit!=9)
{
    then we have to make the next element and put it into queue.
    for eg. 
    val=12     -> possible number ->123
    last_digit=2 
    val=val*10+(last_digit+1);
    val=123
}



Code-: Time->O(N) Space->O(N)
vector<int> sequentialDigits(int low, int high) {
        vector<int>ans;
        queue<int>q;
        for(int i=1;i<=8;i++)
        {
            q.push(i);
        }

        while(q.empty()==false)
        {
            int val=q.front();
            q.pop();

            if(val>=low and val<=high)
            ans.push_back(val);
            if(val>high)
            break;

            int ld=val%10;
            if(ld!=9)
            {
               val*=10;
               val+=ld+1;
               q.push(val);
            }
        }
        return ans;
    }
