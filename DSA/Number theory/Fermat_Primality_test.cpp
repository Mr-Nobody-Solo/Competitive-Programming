//Starting with the name of ALLAH
/*
 ____                  _ 
/ ___|  __ _  __ _  __| |
\___ \ / _` |/ _` |/ _` |
 ___) | (_| | (_| | (_| |
|____/ \__,_|\__,_|\__,_|
                        
 Topic -> Primality test
 Source -> https://cp-algorithms.com/algebra/primality_tests.html   
 Source 2 -> https://youtu.be/meh2ot1P9g0?si=wXm2m_TlbhNsNiEw
 Problem link -> https://www.spoj.com/problems/PON/
 */
#include <iostream>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(nullptr);

long long mul_mod(long long x, long long p, long long mod){
    long long ans{0};
    x = x % mod;
    while(p){
        if(p&1)
            ans = (ans + x)%mod;
        x = (x*2LL)%mod;
        p>>=1;
    }
    return ans%mod;
}

long long binary_power(long long a, long long p, long long mod){
    long long res{1};
    while(p){
        if( p&1 )   //p%2 ==1
            res = mul_mod(res,a,mod);
        p>>=1;
        a = mul_mod(a,a,mod);

    }
    return res % mod;
}

bool check_prime(long long num){
    if(num <= 4)
        return num == 2 or num == 3;
    for(int i{1};i<6;i++){
        long long a = 2+ ( rand() % (num-3));   //as needed a > 1 and a < p-1
        long long res = binary_power(a,num-1,num);
        if(res != 1)
            return false;
    }
    return true;
}

int main( ){
    FIO;

    long long tt,num;
    cin>>tt;
    while(tt--){
        cin>>num;
        cout<<(check_prime(num) ? "YES" : "NO")<<endl;
    }
    return (( 0 - 0 ));
}

//(>.<) (^_^) (*_*) \_(^_^)_/


