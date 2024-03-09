// Starting with the name Allah.
// CSES DP 4 : Coin Combinations II
// https://cses.fi/problemset/task/1636
// source link -> https://youtu.be/HgyouUi11zk?si=RVOStGXkJ-3JVlnA
// space optimized
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
const int mod = 1e9+7;

int main( ){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int n,target;  cin>>n>>target;
    vector<int>coins(n),pre(target+1,0),cur(target+1,0);
    for(int i=0;i<n;i++)
    	cin>>coins[i];
    for(int i=0;i<n;i++){
    	for(int j=0;j<=target;j++){
    		if(j==0)
    			cur[j]=1;
    		else
    			cur[j] = (pre[j] +( (j < coins[i]) ? 0 : cur[j-coins[i]]) ) %mod;
    	}
    	pre = cur;
    }
    cout<<cur[target]<<endl;
    return (( 0 - 0 ));
}
// (-_-) (^_^) (*_*) \_(^_^)_/  
