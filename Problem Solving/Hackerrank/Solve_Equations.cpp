//Starting with the name of ALLAH
// Problem link -> https://www.hackerrank.com/challenges/solve-equations/problem
// pre-requir -> Linear Diophantine Equation 
 // Source -> https://youtu.be/oPgIR_oi5pQ?si=rf5kb6OL81TLwT34
#include<iostream>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(nullptr);
using namespace std;

int extended_gcd(int a, int b, long long& x, long long& y){
    if(not b){
        x = 1;
        y = 0;
        return a;
    }
    long long x1,y1;
    int d = extended_gcd(b,a%b ,x1,y1);
    x = y1;
    y = x1-y1*(a/b);
    return d;
}

long long dis(long long a, long long b) { return (a*a) + (b*b); }
int main( ){
    fastIO;
    int a,b,q,g,c;
    cin>>q;
    while(q--){
        long long x,y;
        cin>>a>>b>>c;
        g = extended_gcd(a,b,x,y);
        
        x *= c/g;
        int b1 = b/g;      //have to add alternative value to as the value of c is fixed.
        int a1 = a/g;

        x = ( (x % b1) + b1) % b1;     //bringing x into positive coordinate

        if(x == 0)      //as x must be greater then zero
            x = b1;

        y =  (c - a*x ) / b;

        while( dis(x,y) > dis(x+b1 ,y-a1) ){   //bringing point closed to origin(0,0).
            x += b1;
            y -= a1;
        }

        cout<<x<<' '<<y<<'\n';
    }
    return (( 0 - 0 ));
}
//(>.<) (^_^) (*_*) \_(^_^)_/

