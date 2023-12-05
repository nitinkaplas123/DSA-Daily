Solution 1-:
1)Using swap inbuilt function 

Solution 2-:
Steps-:
1)Using third variable.


Code-:
void swapNumber(int &a, int &b) {
	int temp=a;
	a=b;
	b=temp;
}



Solution 3-:
Steps-:
1)Using arithmetic expression.

Code-:
void swapNumber(int &a, int &b) {
	a=a+b;
	b=a-b;
	a=a-b;
}