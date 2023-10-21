// https://leetcode.com/problems/find-the-closest-palindrome/

Efficient Approach: This approach is based on a little bit of mathematical understanding and logical intuition.

For any possible number, there are 5 cases:
(Say the number is 4723)

Case 1 – The next closest palindrome has one digit extra : So here it will be 10001.
Case 2 – The next closest palindrome has one digit less: So here it will be 999.
Case 3 – The next closest palindrome has the same number of digits.
For case 3 there are 3 subcases:

The middle digit remains same. Postfix is the mirror image of prefix. So here 47(prefix) – 74(postfix)–>4774.
The middle digit increases by 1. Postfix is the mirror image of prefix. So here 4884.
The middle digit decreases by 1. Postfix is the mirror image of prefix. So here 4664.
Among these 5 candidates:
The candidate having the least absolute difference from the original number is the answer. In this case it is 4774.

Overall, the program iterates over the candidate palindromic numbers and finds the one that is closest to the input number. The program uses basic mathematical operations such as finding the prefix of the input number and creating palindromic versions of numbers to achieve this.

Follow below steps to solve this problem:

Create a vector to store candidate palindromic numbers.
Determine the length of the input number and the middle index.
If the input number has a length of 1, return the string of that number minus 1 as the closest palindromic number.
Add two candidate palindromic numbers to the vector: the smallest palindromic number greater than the input number, and the largest palindromic number smaller than the input number.
Create a vector of three numbers that have the same prefix as the input number: the prefix itself, the prefix incremented by 1, and the prefix decremented by 1.
For each number in the prefix vector, create a palindromic number by appending its reverse to itself. If the input number has an odd length, remove the last character of the reverse before appending.
Add each candidate palindromic number to the vector.
Iterate over the candidate vector and find the candidate with the smallest absolute difference to the input number. If there are multiple candidates with the same absolute difference, select the smallest one.


Code-:
string nearestPalindromic(string n) {
        int len=n.size();
        
        vector<string>candidates;
        string maxi=to_string(pow(10,len)+1);
        string mini=to_string(pow(10,len-1)-1);
        candidates.push_back(maxi);
        candidates.push_back(mini);

        long long mid=(len+1)/2;
        long long prefix=stol(n.substr(0,mid));

        vector<long long>v{prefix,prefix+1,prefix-1};
        
        for(auto x:v)
        {
            string str=to_string(x);
            if(len%2!=0)
            str.pop_back();
            reverse(str.begin(),str.end());
            candidates.push_back(to_string(x)+str);
        }
        
        long long ans=INT_MAX;
        long long res=INT_MAX;
        for(int i=0;i<5;i++)
        {
            long long val=stol(candidates[i]);
            long long diff=abs(val-stol(n));
            if(val!=stol(n) and res>diff)
            {
                res=diff;
                ans=val;
            }
            else if(res==diff)
            ans=min(ans,val);
        }
        return to_string(ans);
    }


Time Complexity->O(log(n)) or O(len)

the main part where you have to calculate time complexity in this code is 
1) count(num)
2)pow(10,digits)
3)str.substr(0,mid)

1 and 2 will run for number of digits or lon(n) time and 3 will run in worst case for mid=(14+1)/2

so you can say your worst case will be log(n) 