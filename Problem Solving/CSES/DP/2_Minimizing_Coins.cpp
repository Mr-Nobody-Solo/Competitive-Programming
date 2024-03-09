// Starting with the name Allah.
// CSES DP 2 : Minimizing Coins
// https://cses.fi/problemset/task/1634
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
    vector<int>coins(n),dp(target+1,1e9);
    dp[0]=0;
    for(int& coin: coins)
        cin>>coin;
    for(int i=1;i<=target;i++)
        for(int& coin: coins)
            if(coin <= i)
                dp[i] = min( dp[i] , dp[i-coin]+1 );
    cout<<(dp[target]==1e9? -1 : dp[target])<<endl;

    return (( 0 - 0 ));
}
// (-_-) (^_^) (*_*) \_(^_^)_/  
