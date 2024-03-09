//Starting with the name of ALLAH
/*
 ____                  _ 
/ ___|  __ _  __ _  __| |
\___ \ / _` |/ _` |/ _` |
 ___) | (_| | (_| | (_| |
|____/ \__,_|\__,_|\__,_|
                        
 Topic -> Number theory -> Extended Euclidean Algorithm 
        -> have to find x and y from gcd(a,b) = x*a + y*b;
 Source -> https://youtu.be/-riWIzpsK7s?si=W0mMDHWgH-XoGXMW
 Time complexity ->  O(log(min(a, b))
 */
#include<iostream>
#include<vector>
#define FIO ios_base::sync_with_stdio(false);cin.tie(nullptr);
using namespace std;

int gcd(int a, int b, int& x, int& y){
    if(b == 0){
        x=1;
        y=0;
        return a;
    }
    int x1,y1;
    int d = gcd(b, a%b, x1, y1);
    x = y1;
    y = x1 - y1*(a/b);
    return d;
}

int main( ){
    FIO;
    int a,b,x,y,d;
    cin>>a>>b;
    
    d = gcd(a,b,x,y);
    cout<<"ax + by = GCD(a,b)"<<endl
        <<"Here: "<<endl
        <<"     a = "<<a<<endl
        <<"     x = "<<x<<endl
        <<"     b = "<<b<<endl
        <<"     y = "<<y<<endl
        <<a<<'*'<<x<<'+'<<b<<'*'<<y<<" = "<<(a*x)+(b*y)<<" = "
        <<"GCD("<<a<<','<<b<<')'<<endl;

    return (( 0 - 0 ));
}
//(>.<) (^_^) (*_*) \_(^_^)_/
