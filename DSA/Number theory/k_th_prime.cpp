//Starting with the name of ALLAH
/*
 ____                  _ 
/ ___|  __ _  __ _  __| |
\___ \ / _` |/ _` |/ _` |
 ___) | (_| | (_| | (_| |
|____/ \__,_|\__,_|\__,_|
                        
 Topic -> number theory -> k-th prime
 Source -> https://youtu.be/Xxn9kMEnYSU
        -> https://www.spoj.com/problems/TDKPRIME/
 Created -> 02/06/2023
 */
#include<iostream>
#include <vector>
using namespace std;
#define N 90000000
bool a[N];
int prime[N];
void sieve(){
    for(int i=2;i*i<=N;i++)
        if(a[i] == false)
            for(int j{i*i};j<N;j+=i)
                a[j]=true;
    int k{1};
    for(int i{2};i<N;i++)
        if(not a[i])
            prime[k++]=i;
}

int main(){
    sieve();
    int q,tmp;
    cin>>q;
    while(q--){
        cin>>tmp;
        cout<<prime[tmp]<<endl;
    }
    return 0; 
}
