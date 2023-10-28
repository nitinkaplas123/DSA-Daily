https://practice.geeksforgeeks.org/problems/palindrome-numbers0942/1

Solution 1-:
Steps-:
1)Make a binary representation of given number and store it into string str.
2)Then reverse the string str 
3)Now compare both the strings.

Code-:
 int isPallindrome(long long int N){
      string str="";
      while(N!=0)
      {
          int rem=N%2;
          str+=(rem+'0');
          N=N/2;
      }
      
      string rev=str;
      reverse(str.begin(),str.end());
      return (rev==str);
    }