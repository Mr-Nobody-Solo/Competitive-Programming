//Starting with the name of ALLAH
/*
 ____                  _ 
/ ___|  __ _  __ _  __| |
\___ \ / _` |/ _` |/ _` |
 ___) | (_| | (_| | (_| |
|____/ \__,_|\__,_|\__,_|
                        
Topic -> Euler's Totient function (or total numbers what are co-prime with N and less then N,) 
Source -> https://youtu.be/5MyAh7zNUyk?si=8Y8BDbGMkeeez8iH
 Euler's Totient function : a function that return how many number not have a common divisor with N and less the N.
 co-prime means which has no common divisor or GCD(x,y)=1 
 */

#include<iostream>
#define FIO ios_base::sync_with_stdio(false);cin.tie(nullptr);
using namespace std;

#define NN 1000001
int PHI[NN];
void phi(){     //sieve on Euler's Totient function
    for(int i{1};i<NN;i++)
        PHI[i]=i;
    for(int i{2};i<NN;i++)      //O (N log(log N))
        if(PHI[i] == i)
            for(int j{i};j<NN; j+=i)
                PHI[j] *= (i-1) ,PHI[j] /= i ;
}

int phi(int N){
    int co_prime = N;
    //O(sqrt(N))
    for(int i{2};i*i<=N;i++){
        if(N%i == 0){      //i is prime number
            co_prime /= i;
            co_prime *= (i-1);
            while( N%i == 0 )
                N /= i;
        }
    }
    if(N>1){  //if N is prime
        co_prime /= N;
        co_prime *= (N-1);
    }
    return co_prime;
    /* using this same technic we can count total divisor of a number 
        num = p1^x * p2^y * ...     //here p1,p2 prime divisor
        divisors =  x+1 * y+1 * ...
    */
}

int main( ){
    FIO;
    phi();
    int tt,num;
    cout<<"Enter how many number you want to check : ";
    cin>>tt;
    while(tt--){
        cout<<"Enter number : ";
        cin>>num;
        cout<<num<<" has : "<<phi(num)<<" co-primes.";
        if(num<NN)
            cout<<'('<<PHI[num]<<" form PHI[])";
        cout<<endl;
    }
    return (( 0 - 0 ));
}
//(>.<) (^_^) (*_*) \_(^_^)_/
