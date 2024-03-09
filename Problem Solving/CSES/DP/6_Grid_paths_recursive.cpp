// Starting with the name Allah.

// CSES DP 6 : Grid Paths
// https://cses.fi/problemset/task/1638/
// https://youtu.be/h0i66IhHgGg?si=XpDH4nTdaNalxnbN

#include<algorithm>
#include<iostream>
#include<vector>
#include<set>
using namespace std;

const int mod = 1e9+7;
vector<string>v;
vector<vector<int>>dp;

int path(int i, int j){
    if(i<0 or j< 0 or v[i][j]=='*') return 0;
    if(i==0 and j==0) return 1;
    int& ways = dp[i][j];
    if(ways != -1) return ways;
    ways = path(i-1,j) + path(i,j-1);
    ways%=mod;
    return ways;
}

int main( ){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int n;  cin>>n;
    v.resize(n);
    dp.assign(n,vector<int>(n,-1));
    for(string& s : v)
        cin>>s;
    cout<<path(n-1,n-1)<<endl;
    return (( 0 - 0 ));
}
// (-_-) (^_^) (*_*) \_(^_^)_/  
