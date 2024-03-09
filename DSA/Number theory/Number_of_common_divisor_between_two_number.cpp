//Starting with the name of ALLAH
/*
 ____                  _ 
/ ___|  __ _  __ _  __| |
\___ \ / _` |/ _` |/ _` |
 ___) | (_| | (_| | (_| |
|____/ \__,_|\__,_|\__,_|
                        
 Topic -> Common divisor between two number
 Source -> https://youtu.be/uCgCMW9CMn4?si=rPxylumIS3QPQQkR
 Source 2 -> https://www.geeksforgeeks.org/common-divisors-of-two-numbers/
 Complexity -> O( Q * 2*sqrt(N))
 */
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(nullptr);

void prime_factorization(long long num , map<int,int>& mp){
    for(long long i{2};i*i<=num;i++){
        if(num % i == 0){
            while(num%i == 0){
                num/=i;
                mp[i]++;
            }
        }
    }
    if(num > 1)
        mp[num]++;
}

int main( ){
    FIO;
    int q;
    cout<<"Enter the number of query";
    cin>>q;
    cout<<endl;
    
    while(q--){
        long long x,y;
        cin>>x>>y;
        cout<<"Total common divisor between "<<x<<" and "<<y<<" -> ";

        if(__gcd(x,y) == 1){
            cout<<1<<endl;
            continue;
        }

        if(x>y)
            swap(x,y);
        map<int,int>mp_prime_cnt;
        prime_factorization(x,mp_prime_cnt);

        long long common_divisors{1};
        for(const auto& [prime ,count] : mp_prime_cnt){
            if(y % prime)
                continue;
            int cnt{0};
            while(y % prime == 0){
                y /= prime;
                cnt++;
            }
            common_divisors *= min(mp_prime_cnt[prime] , cnt)+1;
        }

        cout<<common_divisors<<endl;
    }
    return (( 0 - 0 ));
}

//INTPUT : 12 AND 24 -> Have 6 common divisor {1,12,2,6,3,4}
//(>.<) (^_^) (*_*) \_(^_^)_/


