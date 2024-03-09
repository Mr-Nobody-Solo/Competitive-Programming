//Starting with the name of ALLAH
/*
 ____                  _ 
/ ___|  __ _  __ _  __| |
\___ \ / _` |/ _` |/ _` |
 ___) | (_| | (_| | (_| |
|____/ \__,_|\__,_|\__,_|
                        
 Topic -> dp -> longest common sub-sequence
 Source -> https://youtu.be/mNrzyuus2h4
 Created -> 20/05/2023
 */
#include <iostream>
#include <vector>
using namespace std;

int dp[(int)1e5+100];

int LIS(int i,vector<int>& v){
    if(dp[i])
        return dp[i];
    int ans = 1;
    for(int j=0;j<i;j++)
        if(v[i]>v[j])
            ans = max(ans , LIS(j,v)+1 );
    return dp[i] = ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(auto& i : v)
        cin>>i;
    int ans = 0;
    for(int i{0};i<n;i++)
        ans = max(ans,LIS(i,v));
    cout<<ans<<endl;
    return (( 0 - 0 ));
}
