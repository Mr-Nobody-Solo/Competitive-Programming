//Starting with the name of ALLAH
/*
 ____                  _ 
/ ___|  __ _  __ _  __| |
\___ \ / _` |/ _` |/ _` |
 ___) | (_| | (_| | (_| |
|____/ \__,_|\__,_|\__,_|
                        
 Topic -> Segmented sieve from range L to R (where R <= 10^12 and R-L-1 <= 10^6)
 Source -> https://youtu.be/uCgCMW9CMn4?si=rPxylumIS3QPQQkR
 */
#include <iostream>
#include <vector>
#include <bitset>
#include <cmath>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(nullptr);

#define N 1000100
vector<int>primes;
vector<bool>range_primes(N);
bitset<1000010>SIEVE;

void sieve(){
    for(int i{2};i<N;i++)
        if(not SIEVE[i])
            for(int j{i+i};j<N;j+=i)
                SIEVE[j]=1;
    for(int i{2};i<N;i++)
        if(not SIEVE[i])
            primes.push_back(i);
}

void segmented_sive(long long L,long long R){
    if(L == 1)
        range_primes[0]=true;
    int last_divisor = ceil(sqrt(R));

    for(int i{0};primes[i]<=last_divisor;i++){

        long long starting_num = L;
        if(primes[i]>=starting_num)
            starting_num = 2*primes[i];
        else
            starting_num = (L/primes[i])*primes[i];
        if(starting_num < L or starting_num == (long long)primes[i])
            starting_num += primes[i];

        for(long long j{starting_num};j<=R;j += primes[i])
            range_primes[j-L]=true;
    }
}

int main( ){
    FIO;
    sieve();
    long long L,R;
    cin>>L>>R;
    if(L<1)
        L=1;
    if(R > (long long)1e12)
        cout<<"R must be less then 10^12"<<endl;
    else if(R-L+1 > (int) 1e7)
        cout<<"Range is larger for fit on vector"<<endl;
    else{
        segmented_sive(L,R);
        cout<<"Prime number from "<<L<<" to "<<R<<':'<<endl;
        for(int i{0};i<(R-L+1);i++)
            if(not range_primes[i])
                cout<<i+L<<endl;
    }
    return (( 0 - 0 ));
}

//MAX input : 999999000000 1000000000000
//(>.<) (^_^) (*_*) \_(^_^)_/

