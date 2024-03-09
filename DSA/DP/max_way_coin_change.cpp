//Starting with the name of ALLAH
/*
 ____                  _ 
/ ___|  __ _  __ _  __| |
\___ \ / _` |/ _` |/ _` |
 ___) | (_| | (_| | (_| |
|____/ \__,_|\__,_|\__,_|
                        
 Topic -> DP -> coin change -> the number of ways (combination).
 Source -> https://youtu.be/PoTE56n_It8
 Created -> 03/06/2023
 */
#include <iostream>
#include <vector>
using namespace std;

int dp[333][5555];
int maxWay(int idx,int amount,vector<int>& coins){
    if(not amount)  return 1;
    if(idx<0)   return 0;
    if(dp[idx][amount])
        return dp[idx][amount];
    int ways{0};
    for(int coin_amount = 0; coin_amount<= amount ; coin_amount += coins[idx])
        ways += maxWay(idx-1, amount-coin_amount, coins);
    return dp[idx][amount] = ways;
}

int main(){
    int amount,num;
    cin>>num>>amount;
    vector<int>coins(num);
    for(auto& it : coins)
        cin>>it;
    cout<<maxWay(coins.size()-1,amount,coins)<<endl;
    return (( 0 - 0 ));
}

/*
input:
3 5000
1 2 5
*/