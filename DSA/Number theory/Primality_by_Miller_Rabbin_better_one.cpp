//Starting with the name of ALLAH
/*
 ____                  _ 
/ ___|  __ _  __ _  __| |
\___ \ / _` |/ _` |/ _` |
 ___) | (_| | (_| | (_| |
|____/ \__,_|\__,_|\__,_|
                        
 Topic -> Primality test -> Miller Rabin (Almost deterministic)
 Source -> https://cp-algorithms.com/algebra/primality_tests.html   
 Source 2 -> https://youtu.be/--fr2IS0XxM?si=jDP_yvS3B2w3hFfM
 Problem link -> https://www.spoj.com/problems/PON/
 */
#include <iostream>
using namespace std;


//only use to handle long long (64 bit) overflow 
long long mul_mod(long long base,long long power,long long mod){
    long long ans = 0;
    base %= mod;
    while(power){
        if(power & 1)
            ans = (ans + base)% mod;
        base = (base * 2LL) % mod;
        power >>= 1;
    }
    return ans % mod;
}

long long bin_power(long long base ,long long power,long long mod){
    long long ans = 1;
    while(power){
        if(power & 1)
            ans = mul_mod(ans,base,mod);    //or -> ans = ((__int128)ans * base)% mod;
        base = mul_mod(base,base,mod);      //or -> base = ((__int128) base * base)% mod;
        power >>= 1;
    }
    return ans % mod;
}

bool check_composite(long long a, long long s,long long d,long long num){
    long long x = bin_power(a,d,num);
    if(x == 1 or x == num-1 )     //as a^d - 1 mod num == 0  or  a^d + 1 mod num == 0
        return false;
    while(s--){
        x = bin_power(x,2,num);     //or -> x = ((__int128)x*x) % num;
        if( x == num-1 )
            return false;
    }
    return true;
}

bool miller_rabin_primality(long long num){
    if(num <= 4 )
        return num == 2 or num == 3;

    //( a^(2^s)*d ) mod num == -1 
    long long d{num-1},s{0};
    while(d&1 == 0)   //while d is being odd
        s++,d>>=1;

    // //for non deterministic 
    // for(long long i{0};i<6;i++){
    //     long long a = 2 + (rand()+i) % (num-3);
    //     if(check_composite(a,s,d,num))
    //         return false;
    // }

    // for deterministic 
    for( int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}){
        if(num == a)
            return true;
        if(check_composite(a,s,d,num))
            return false;
    }
    return true;
}


int main( ){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long tt,num;
    cin>>tt;
    while(tt--){
        cin>>num;
        cout<<(miller_rabin_primality(num) ? "YES" : "NO")<<endl;
    }
    return (( 0 - 0 ));
}

//(>.<) (^_^) (*_*) \_(^_^)_/


