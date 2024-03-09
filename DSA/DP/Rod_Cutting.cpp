/*>> Starting with the name of Allah. <<*/
//Source -> https://youtu.be/KnzlqtUDfIc
//Problem link -> https://practice.geeksforgeeks.org/problems/rod-cutting0840/1
int dp[1010];
class Solution{
    int nth_value(int len_left,int price[]){
        if(not len_left) return 0;
        if(dp[len_left]>=0) return dp[len_left];
        int maxValue{0};
        for(int i{1};i<=len_left;i++){
            maxValue = max(maxValue,nth_value(len_left-i,price)+price[i-1]);
        }
        return dp[len_left] = maxValue;
    }
  public:
    int cutRod(int price[], int n) {
        memset(dp,-1,sizeof(dp));
        return nth_value(n,price);
    }
};