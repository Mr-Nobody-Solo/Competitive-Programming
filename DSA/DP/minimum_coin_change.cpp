//Starting with the name of ALLAH
/*
 ____                  _ 
/ ___|  __ _  __ _  __| |
\___ \ / _` |/ _` |/ _` |
 ___) | (_| | (_| | (_| |
|____/ \__,_|\__,_|\__,_|
                        
 Topic -> dp -> coin change
 Source -> https://youtu.be/PoTE56n_It8
 Created -> 21/05/2023
 */
#include <iostream>
#include <vector>
#include <climits>
#include <cstring>
using namespace std;

int dp[(int)1e4+100];

int minCoin(int amount,vector<int>& coins){
    if(not amount)
        return 0;
    if(dp[amount] != -1)
        return dp[amount];
    int coin{INT_MAX};
    for(int& value : coins){
        if(value <= amount){
            coin = min(coin+0LL,minCoin(amount-value,coins)+1LL);
        }         
    }
    return dp[amount] = coin;
}

int main(){
    memset(dp,-1,sizeof(dp));
    int n,amount;
    cin>>n>>amount;
    vector<int> coins(n);
    for(auto& i : coins)
        cin>>i;
    int ans{minCoin(amount,coins)};
    cout<<(ans == INT_MAX ? -1 : ans)<<endl;
    return (( 0 - 0 ));
}


