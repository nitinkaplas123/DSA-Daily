Solution 1-:
Steps-:
1)Make every pair using 2 for loops.
2)check if this pair string is palidrome or not.

Code-: Time=>O(N^2*M) here N is the size of array and M is the len of string for which we are checking for palidrome.
bool isPalidrome(string &str1,string &str2)
{
        string str=str1+str2;
        int low=0;
        int high=str.length()-1;
        while(low<=high)
        {
            if(str[low]!=str[high]) return false;
            low++;
            high--;
        }
        return true;
}

bool palindromepair(int N, string arr[]) {
        for(int i=0;i<N;i++)
        {
            string str1=arr[i];
            for(int j=0;j<N;j++)
            {
                if(i!=j and isPalidrome(str1,arr[j]))
                return true;
            }
        }
        return false;
}



Solution 2-:
Steps-:
1)