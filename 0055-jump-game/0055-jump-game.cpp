class Solution {
public:

    bool jumper(int i,vector<int>& nums,vector<int>& dp){

        if(i==nums.size()-1) return true;

        if(dp[i]!=-1) return dp[i];

        bool ans = false;
        for(int j=i+1;j<=min(i + nums[i], (int)nums.size() - 1);j++){
             ans =  jumper(j,nums,dp);
             if (ans) break;
        }

       dp[i] = ans;

        return dp[i];

        }

    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return jumper(0,nums,dp);
    }
};