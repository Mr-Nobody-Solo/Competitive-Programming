//Starting with the name of ALLAH
/*
 ____                  _ 
/ ___|  __ _  __ _  __| |
\___ \ / _` |/ _` |/ _` |
 ___) | (_| | (_| | (_| |
|____/ \__,_|\__,_|\__,_|
                        
 Topic -> dp-> Knapsack 1
 Problem link -> https://atcoder.jp/contests/dp/tasks/dp_d
 Source -> https://youtu.be/o0NtrkItjws
 Created -> 11/06/2023
 */
#include <iostream>
#include <vector> 
#include <algorithm>
#include <cstring>
using namespace std;
#define weight (int)1e5+100
long long dp[111][weight];

long long max_value(int i, int capacity, vector<pair<int,int>>& v){
    if(not capacity or i<0)
        return 0;
    if(dp[i][capacity]>=0)
        return dp[i][capacity];
    long long max_cost{0};
    if(v[i].first <= capacity)
        max_cost = max_value(i-1,capacity-v[i].first,v)+v[i].second;
    max_cost = max(max_cost,max_value(i-1,capacity,v));
    return dp[i][capacity] = max_cost;
}

int main(){
    memset(dp,-1,sizeof(dp));
    int items,capacity;
    long long ans;
    cin>>items>>capacity;
    vector<pair<int,int>>v(items);
    for(auto& it : v)
        cin>>it.first>>it.second;
    cout<<max_value(v.size()-1,capacity,v)<<endl;
    return (( 0 - 0 ));
}
