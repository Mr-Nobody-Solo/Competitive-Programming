//Starting with the name of Allah.
/*
Problem link -> https://leetcode.com/problems/longest-common-subsequence/
Source -> https://youtu.be/Q0o9sU1r0FY
*/
int dp[1010][1010];
class Solution {
    int lcss(int i, int j, string& s1, string& s2){
        if(i<0 or j<0 ) return 0;
        if(dp[i][j]>-1)return dp[i][j];
        if(s1[i] == s2[j])
            return dp[i][j] = lcss(i-1,j-1,s1,s2) + 1;
        int ans = lcss(i,j-1,s1,s2);
        ans = max(ans, lcss(i-1,j,s1,s2));
        return dp[i][j] = ans;
    }
    
public:
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp,-1,sizeof(dp));
        return lcss(text1.size()-1,text2.size()-1,text1,text2);
    }
};