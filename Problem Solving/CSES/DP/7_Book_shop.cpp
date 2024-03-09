// Starting with the name Allah.

// CSES DP 7 : Book Shop
// https://cses.fi/problemset/task/1158
// https://youtu.be/h0i66IhHgGg?si=XpDH4nTdaNalxnbN

#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<set>
using namespace std;

int price[1010],page[1010];
int dp[1010][100100];

int main( ){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int n,money;  cin>>n>>money;

    for(int i=1; i<=n;i++)
        cin>>price[i];
    for(int i=1; i<=n;i++)
        cin>>page[i];
    for(int i=1;i<=n;i++){
        for(int j=0;j<=money;j++){
            int take=0;
            if(j>=price[i])
                take = dp[i-1][j-price[i]] + page[i];
            // dp[i][j] = max( dp[i-1][j] , dp[i-1][j-price[i]] + page[i] );
            dp[i][j] = max( dp[i-1][j] , take );
        }
    }
    cout<<dp[n][money]<<endl;
    return (( 0 - 0 ));
}

// Hence the time limits is 1s so it can not be solve by direct recursive solution present.

// (-_-) (^_^) (*_*) \_(^_^)_/  

