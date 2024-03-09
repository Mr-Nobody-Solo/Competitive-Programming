// Starting with the name Allah.

// CSES DP 4 : Removing Digits
// https://cses.fi/problemset/task/1637
// source link -> https://youtu.be/YZDjUDW4xwc?si=KuRSDFkzVeoxvxgl

#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<int>dp;

int minCnt(int val){
	if(val == 0) return 0;
	if(dp[val] != -1) return dp[val];
	int tmp = val,digit;
	dp[val] = 1e7;
	while(tmp>0){
		digit = tmp%10;
		tmp/=10;
		if(digit>0 and val >= digit)
			dp[val] = min( dp[val] , minCnt(val-digit)+1);
	}
	return dp[val];
}
	
int main( ){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int n;	cin>>n;
    dp.assign(n+1,-1);
    cout<<minCnt(n)<<endl;
    return (( 0 - 0 ));
}
// (-_-) (^_^) (*_*) \_(^_^)_/  
