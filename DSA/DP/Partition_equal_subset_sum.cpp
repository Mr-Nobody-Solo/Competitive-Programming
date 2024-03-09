//Starting with the name of Allah.
//topic -> sumset sum
//source -> https://youtu.be/G46kdLkQ_Sw
//problem link -> https://leetcode.com/problems/partition-equal-subset-sum/

int dp[211][20010];
class Solution {
    bool isPossible(int idx,int new_sum,int total_sum, vector<int>&nums){
        if(new_sum == total_sum) return true;
        if(idx < 0 )return false;
        if(dp[idx][total_sum] != -1) return dp[idx][total_sum];
        bool check = isPossible(idx-1,new_sum,total_sum,nums);
        if(not check)
            check = isPossible(idx-1,new_sum+nums[idx],total_sum-nums[idx],nums);
        return dp[idx][total_sum] = check;
    }
public:
    bool canPartition(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int sum{0};
        for(int& i : nums)
            sum+=i;
        return isPossible(nums.size()-1,0,sum,nums);
    }
};

/*
int dp[210][10010];
class Solution {
    bool isPossible(int idx,int sum, vector<int>&nums){
        if(not sum) return true;
        if(idx < 0 )return false;
        if(dp[idx][sum] != -1) return dp[idx][sum];
        bool check = isPossible(idx-1,sum,nums);
        if(not check and sum-nums[idx]>=0)
            check = isPossible(idx-1,sum-nums[idx],nums);
        return dp[idx][sum] = check;
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum{0};
        for(int& i : nums)
            sum+=i;
        if(sum&1)return false;
        sum>>=1;
        memset(dp,-1,sizeof(dp));
        return isPossible(nums.size()-1,sum,nums);
    }
};
*/