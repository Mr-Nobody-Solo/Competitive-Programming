// Starting with the name Allah.

// CSES DP 7 : Book Shop
// https://cses.fi/problemset/task/1158
// https://youtu.be/h0i66IhHgGg?si=XpDH4nTdaNalxnbN
// space optimized

#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<set>
using namespace std;

int main( ){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int n,money;  cin>>n>>money;
    vector<int>price(n+1),page(n+1),pre(money+1,0),cur(money+1,0);
    for(int i=1; i<=n;i++)
        cin>>price[i];
    for(int i=1; i<=n;i++)
        cin>>page[i];
    for(int i=1;i<=n;i++){
        for(int j=0;j<=money;j++){
            int take=0;
            if(j>=price[i])
                take = pre[ j-price[i] ] + page[i];
            // dp[i][j] = max( dp[i-1][j] , dp[i-1][j-price[i]] + page[i] );
            cur[j] = max( pre[j] , take );
        }
        pre = cur;
    }
    cout<<cur[money]<<endl;
    return (( 0 - 0 ));
}

// 258924
// (-_-) (^_^) (*_*) \_(^_^)_/  

