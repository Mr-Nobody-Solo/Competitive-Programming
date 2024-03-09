// Starting with the name Allah.
// CSES DP 1 : Dice Combinations
// https://cses.fi/problemset/task/1633/
// source link -> https://youtu.be/YZDjUDW4xwc?si=KuRSDFkzVeoxvxgl
#include<algorithm>
#include<iostream>
#include<vector>
#include<set>
using namespace std;
const int mod = 1e9+7;
int main( ){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int n;  cin>>n;
    vector<int>previous={0,0,0,0,0,1},current(6,0);
    for(int i=0;i<n;i++){
        for(int i=1;i<6;i++)
            current[i-1] = previous[i];
        current[5]=0;
        for(int i=0;i<6;i++)
            current[5] = (current[5] + previous[i])%mod;
        previous = current;
    }
    cout<<current.back()<<endl;
    return (( 0 - 0 ));
}
// (-_-) (^_^) (*_*) \_(^_^)_/  
