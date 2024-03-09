//Starting with the name of ALLAH
/*
 ____                  _ 
/ ___|  __ _  __ _  __| |
\___ \ / _` |/ _` |/ _` |
 ___) | (_| | (_| | (_| |
|____/ \__,_|\__,_|\__,_|
                        
 Topic -> dp -> knapsack 2
 Problem link -> https://atcoder.jp/contests/dp/tasks/dp_e
 Source -> https://youtu.be/gHVtY5raAQg
 Created -> 13/06/2023
 */
#include <iostream>
#include <vector> 
#include <climits>
using namespace std;
int dp[111][100111];
int minWeight(int idx,int sum,vector<pair<int,int>>&v){
    if(sum == 0)  return 0;
    if(idx<0 ) return INT_MAX;; 
    if(dp[idx][sum]) return dp[idx][sum];
    int wt = minWeight(idx-1,sum,v);
    if(v[idx].second <= sum)
        wt = min(wt+0LL,minWeight(idx-1,sum-v[idx].second,v)+0LL+v[idx].first);
    return dp[idx][sum] = wt;
}

int main(){
    int n,wt,sum{0};
    cin>>n>>wt;
    vector<pair<int,int>> v(n);
    for(auto& pr : v){
        cin>>pr.first>>pr.second;
        sum += pr.second;
    }
    minWeight(v.size()-1,sum,v);
    for(int i{sum};i>=0;i--){
        if(minWeight(v.size()-1,i,v)<= wt){
            cout<<i<<endl;
            break;
        }
    }
    return (( 0 - 0 ));
}