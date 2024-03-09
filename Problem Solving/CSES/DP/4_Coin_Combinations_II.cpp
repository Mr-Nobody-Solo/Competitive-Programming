// Starting with the name Allah.
// CSES DP 4 : Coin Combinations II
// https://cses.fi/problemset/task/1636
// source link -> https://youtu.be/YZDjUDW4xwc?si=KuRSDFkzVeoxvxgl
//Can not optimize space so much for target value.
#include<algorithm>
#include<iostream>
#include<vector>
#include<set>
using namespace std;
const int mod = 1e9+7;
int main( ){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int n,target;  cin>>n>>target;
    vector<int>coins(n),dp(target+1,0);
    for(int& coin: coins)
        cin>>coin;
    dp[0]=1;
    for(int& coin: coins)
    	for(int i=1;i<=target;i++)
            if(coin <= i)
                dp[i] = ( dp[i] + dp[i-coin] )%mod;
    cout<<dp[target]<<endl;
 
    return (( 0 - 0 ));
}
// (-_-) (^_^) (*_*) \_(^_^)_/  
