class Solution {
public:
int solve(int idx, vector<int>& nums,vector<int>& dp){
    if(idx<0) return 0;
    if(idx==0) return nums[idx];
    if(dp[idx]!=-1) return dp[idx];
    int norob = solve(idx-1,nums,dp);
    int rob = solve(idx-2,nums,dp)+nums[idx];
    return dp[idx] = max(norob, rob);
}
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return solve(nums.size()-1,nums,dp);
    }
};