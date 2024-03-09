// Starting with the name Allah.

// CSES DP 6 : Grid Paths
// https://cses.fi/problemset/task/1638/
// https://youtu.be/h0i66IhHgGg?si=XpDH4nTdaNalxnbN
//space optimized
#include<algorithm>
#include<iostream>
#include<vector>
#include<set>
using namespace std;

const int mod = 1e9+7;

int main( ){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int n;  cin>>n;
    vector<string>v(n);
    vector<int>pre(n,0),cur(n,0);
    for(string& s : v)
        cin>>s;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(v[i][j]=='*')    cur[j]=0;
            else if( i==0 and j==0 )    cur[i]=1;
            else    cur[j] = (pre[j] + ( (j>0)? cur[j-1] : 0) )%mod; 
        }    
        pre = cur;    
    }
    cout<<cur[n-1]<<endl;
    return (( 0 - 0 ));
}

/*
//Not space optimized code
    vector<vector<int>>dp(n,vector<int>(n,0));
    for(string& s : v)
        cin>>s;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(v[i][j]=='*') dp[i][j]=0;
            else if(i == 0 and j==0) dp[i][j]=1;
            else{
                int up=0,left=0;
                if(i!=0) left = dp[i-1][j]; 
                if(j!=0) up = dp[i][j-1];
                dp[i][j] = (up + left)%mod; 
            }
        }        
    }
    cout<<dp[n-1][n-1]<<endl;
*/

// (-_-) (^_^) (*_*) \_(^_^)_/  

