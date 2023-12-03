Solution 1-: Using bitwise opeartor.

Steps-:
1)if the and opeartor with N &1 is 1 means the first bit is set from right side which 
  means its a odd number.

Code-:
string oddEven(int N){
    if(N&1==1) return "odd";
    else return "even";
}
