https://www.geeksforgeeks.org/problems/print-bracket-number4058/1

Code-: Time->O(N) Space->O(N)
vector<int> bracketNumbers(string S)
{
	    vector<int>v;
	    stack<int>st;
	    
	    int left=1;
	    for(int i=0;i<S.length();i++)
	    {
	        if(S[i]=='(')
	        {
	            v.push_back(left);
	            st.push(left);
	            left++;
	        }
	        else if(S[i]==')')
	        {
	            v.push_back(st.top());
	            st.pop();
	        }
	        else
	        continue;
	    }
	    return v;
}