Solution 1-:

Formula-> 
lcm*gcd=A*B.
lcm=A*B/gcd.


Code-:  O(Log(min(A,B)))
long long int helper1(long long A,long long B)
{
        if(B==0) return A;
        return helper1(B,A%B);
}

long long int helper2(long long A,long long B,long long int gcd)
{
        return A*B/gcd;
}

vector<long long> lcmAndGcd(long long A , long long B) {
       long long int gcd=helper1(A,B);
       long long int lcm=helper2(A,B,gcd);
       return {lcm,gcd};
    }
