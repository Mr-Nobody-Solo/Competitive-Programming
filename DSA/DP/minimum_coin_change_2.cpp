//problem link -> https://leetcode.com/problems/coin-change/submissions/963720564/
class Solution {
    int dp[30][10010];
    int minCoin(int idx,int amount,vector<int>& coins){
        if(not amount){
            return 0 ;
        }
        if(idx<0)
            return INT_MAX;
        if(dp[idx][amount]>=0)
            return dp[idx][amount];
        int ans{INT_MAX};
        for(int coin_amount{0};coin_amount<=amount;coin_amount+=coins[idx]){
            int tmp = minCoin(idx-1,amount-coin_amount,coins);
            if(tmp != INT_MAX)
                ans = min(ans,tmp+coin_amount/coins[idx]);
        }
        return dp[idx][amount] = ans;
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        memset(dp,-1,sizeof(dp));
        int ans = minCoin(coins.size()-1, amount, coins);
        return ans == INT_MAX ? -1 : ans;
    }
};