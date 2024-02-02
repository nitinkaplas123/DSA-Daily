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



Solution 2-: Using BFS Approach
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




Solution 3-:
Steps-:
1)Make a vector where we put all the possible numbers in it.
2)Now traverse the vector v 
  1. if v[i] is in the range then put it into vector v.
  2. if v[i]>high break the loop.
  3. if v[i]<low go to next value ->continue;


Code-: Time->O(1) Space->O(1)
vector<int> sequentialDigits(int low, int high) {
        vector<int>ans;
        vector<int>v={12,23,34,45,56,67,78,89,
                      123,234,345,456,567,678,789,
                      1234,2345,3456,4567,5678,6789,
                      12345,23456,34567,45678,56789,
                      123456,234567,345678,456789,
                      1234567,2345678,3456789,
                      12345678,23456789,
                      123456789};

        int n=v.size();
        for(int i=0;i<n;i++)
        {
            if(v[i]>=low and v[i]<=high)
            ans.push_back(v[i]);
            else if(v[i]>high)
            break;
            else
            continue;
        }
        return ans;
    }