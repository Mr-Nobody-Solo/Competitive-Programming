//Starting with the name of ALLAH
/*
 ____                  _ 
/ ___|  __ _  __ _  __| |
\___ \ / _` |/ _` |/ _` |
 ___) | (_| | (_| | (_| |
|____/ \__,_|\__,_|\__,_|
                        
 Topic -> Number theory -> Linear Diophantien Equation (LDA)
        -> have to find x and y from equation a*x + b*y = c where a,b and c is given.
 Pre-require -> Extended Euclidean Algorithm 
 Source -> https://youtu.be/oPgIR_oi5pQ?si=rf5kb6OL81TLwT34
 Time complexity ->  O( Q * log(min(a, b) )
 */
#include<iostream>
#define FIO ios_base::sync_with_stdio(false);cin.tie(nullptr);
using namespace std;

int extended_gcd(int a, int b, int& x, int& y){
    if(not b){
        x = 1;
        y = 0;
        return a;
    }
    int x1,y1;
    int d = extended_gcd(b,a%b ,x1,y1);
    x = y1;
    y = x1-y1*a/b;
    return d;
}

bool find_a_solution(int a, int b, int c, int& x ,int& y){
    int x1,y1;
    int g = extended_gcd(abs(a),abs(b),x1,y1);
    if(c % g)
        return false;
    x = x1 * c/g;
    y = y1 * c/g;
    if(a<0)
        x = -x;
    if(b<0)
        y = -y;
    return true;
}

int main( ){
    FIO;
    int a,b,x,y,c,q;
    cout<<"ax + by = c Linear Diophentien Equation solver."<<endl;
    cout<<"Enter the number query number : ";
    cin>>q;
    while(q--){
        cout<<"Enter a, b, c separated by spaces : ";
        cin>>a>>b>>c;
        if(find_a_solution(a,b,c,x,y) == false)
            cout<<"This equation can not be solved."<<endl;
        else
            cout<<"(x , y) = ("<<x<<" , "<<y<<')'<<endl;
        // x and y can be modify without changing the actual equation 
        // adding k times b/gcd(a,b) to x 
        // and subtracting k times a/(gcd(a,b)) form y.
    }
    return (( 0 - 0 ));
}
//(>.<) (^_^) (*_*) \_(^_^)_/

/*
Input:
2
-2 -3 10
4 6 7
*/
