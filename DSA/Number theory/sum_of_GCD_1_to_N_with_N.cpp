/*
Starting with the name of ALLAH
 ____                  _ 
/ ___|  __ _  __ _  __| |
\___ \ / _` |/ _` |/ _` |
 ___) | (_| | (_| | (_| |
|____/ \__,_|\__,_|\__,_|
                        
Topic -> Getting sum of GCD form 1 to N with N by the help of Euler's Totient Phi function 
Source -> https://youtu.be/zA43PhuavsI?si=6WGnea5zCyS6aPPO
requirement -> Euler's Totient function  
*/
#include<iostream>
#define FIO ios_base::sync_with_stdio(false);cin.tie(nullptr);
using namespace std;

#define mod 1000000007
#define N 1000001
int PHI[N];
void phi(){     //sieve on Euler's Totient function
    for(int i{1};i<N;i++)
        PHI[i]=i;
    for(int i{2};i<N;i++)      //O (N log N)
        if(PHI[i] == i)
            for(int j{i};j<N; j+=i)
                PHI[j] *= (i-1) ,PHI[j] /= i ;
}

long long getCount(int d, int num){
    return PHI[num/d];
}

int main( ){
    //O ( NlogN + Q*sqrt(N) )
    FIO;
    phi();  // O(N log N)
    int q,num;
    cout<<"Enter how many number you want to check : ";
    cin>>q;
    while(q--){     //O ( Q*sqrt(N) )
        cout<<"Enter number : ";
        cin>>num;
        long long sum{0};
        for(int i{1};i*i<=num;i++)
            if(num%i == 0){
                int d1 = i;     //divisors less then sqrt(num) 
                int d2 = num/i;     //divisors greater then sqrt(num)
                /* *** all the numbers having GCD d with num == all the numbers co-prime with num/d
                 * as GCD(x,num) = d then GCD(x/d ,num/d) = 1 which is Euler's Totient phi function. */
                sum = (sum + d1 * (getCount(d1,num))%mod )%mod;    
                if(d1 != d2)
                    sum = (sum + d2 * (getCount(d2,num))%mod )%mod;  
            }
        cout<<"The sum of GCD(1 to "<<num<<","<<num<<") is : "<<sum<<endl;
    }    
    return (( 0 - 0 ));
}

//(>.<) (^_^) (*_*) \_(^_^)_/
