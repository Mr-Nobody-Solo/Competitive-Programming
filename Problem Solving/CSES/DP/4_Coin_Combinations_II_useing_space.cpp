// Starting with the name Allah.
// CSES DP 4 : Coin Combinations II
// https://cses.fi/problemset/task/1636
// source link -> https://youtu.be/HgyouUi11zk?si=RVOStGXkJ-3JVlnA	
#include<iostream>
#include<cstring>
using namespace std;

const int mod = 1e9+7;
int coins[111];
int dp[105][1000010];

int main( ){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int n,target;  cin>>n>>target;
    for(int i=0;i<n;i++)
    	cin>>coins[i];
    for(int i=0;i<n;i++){
    	for(int j=0;j<=target;j++){
    		if(j==0)
    			dp[i][j]=1;
    		else{
    			int with_out_take_this = 0;
    			if(i-1>=0)
    				with_out_take_this = dp[i-1][j];
    			int using_this = 0;
    			if(j >= coins[i])
    			using_this = dp[i][j-coins[i]];
    			// dp[i][j] = dp[i-1][j] + dp[i][j-coins[i]]; 
    			dp[i][j] = (with_out_take_this + using_this) %mod;		//handling boundery case
    		}
    	}
    }
    cout<<dp[n-1][target]<<endl;
    return (( 0 - 0 ));
}
// (-_-) (^_^) (*_*) \_(^_^)_/  
