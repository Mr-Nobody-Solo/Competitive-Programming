//Starting with the name of ALLAH
/*
 ____                  _ 
/ ___|  __ _  __ _  __| |
\___ \ / _` |/ _` |/ _` |
 ___) | (_| | (_| | (_| |
|____/ \__,_|\__,_|\__,_|  

*/

// source ->https://youtu.be/ytxsaKqAPng

#include <iostream>
#include <string>
#include <bitset>
#include <iomanip> //needed to see true or false
#include <vector>
// #include<bits/std++.h>
using namespace std;


vector<int> v;
bitset<10001> b; //as bitset must be fixed before compile. (-_- )
void sieve(int);

int main(){
    bitset<5>b;    //caution sized is fixed can not change in compile time

    cout<<"after initialize :";
    cout<<b<<endl;

    b.reset();
    cout<<"after reset :";
    cout<<b<<endl;

    cout<<"after set :";
    b.set();        //set all bit to one
    cout<<b<<endl;

    b.reset();
    cout<<"after reset :";
    cout<<b<<endl;

    bitset<10> c(string("1110"));   //only for new initialization
    cout<<"after initially set bit by string (c) :";
    cout<<c<<endl;

    bitset<7> d(7);     //only for new initialization
    cout<<"after initially set bit by integer(d) :";
    cout<<d<<endl;

    d.flip();
    cout<<"after flipping (d) :";
    cout<<d<<endl;

    d.flip();
    cout<<"Again after flipping (d) :";
    cout<<d<<endl;

    cout<<"size of d is :"<<d.size()<<endl;
    cout<<"The number of set bit in d is :"<<d.count()<<endl;
    cout<<"The number of unset bit in d is :"<<d.size()-d.count()<<endl;

    //set and unset a specific bit
    bitset<5> e;
    e.set(1);   //index is count from back 
    e[2]=1;   //index is count from back 
    cout<<"After setting indexes 1,2 of bit e :"<<e<<endl;

    // e.reset(1);
    e[1]=0;
    cout<<"After resetting index 1 of bit e :"<<e<<endl;

    e.set();
    cout<<"e now:"<<e<<endl;

    e>>=2; // left shift
    // e = e>>2;    //same as before
    cout<<"e after left shift 2 times :"<<e<<endl;

    e<<=3; // right shift
    // e = e<<3;    //same as before
    cout<<"e after right shift 3 times :"<<e<<endl;

    //Now bit-wise operation
    bitset<4> x("0011");
    bitset<4> y("0101");
    cout<<"x = "<<x<<endl;
    cout<<"y = "<<y<<endl;

    cout<<"x&y (and):"<<(x&y)<<endl;
    cout<<"x|y (or):"<<(x|y)<<endl;
    cout<<"x^y (x-or):"<<(x^y)<<endl;

    cout<<boolalpha;    //need for see true or false 
    x.set();
    cout<<"Is all bit of x is set :"<<x.all()<<endl;
    cout<<"Is none bit of x is set :"<<x.none()<<endl;

    sieve(1000);
    cout<<"\nFirst 50 prime number are given below :"<<endl;
    for(int i{0};i<51;i++){
        cout<<v[i]<<" ";
        if(!(i%10) and i!=0)cout<<endl;
    }

    return 0;
}

//sieve by using bit-set 
void sieve(int upper_bound){
    b.set();   //b must declared globally with size before compile
    b[0]=b[1]=0;
    v.push_back(2);
    for(int i{3};i<=upper_bound+1;i+=2){    //Caution here loop break condition is not i*i<=upper_bound
        if(b[i]){
            v.push_back(i);
            for(int j{i*i};j<upper_bound+1;j+=i){
                b[j]=0;
            }
        }
    }
}