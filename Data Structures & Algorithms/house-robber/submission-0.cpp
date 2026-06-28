class Solution {
public:
    int solve(int index , vector<int>& nums , vector<int>& dp ){
        if(index==0) return nums[index];
        if(index == 1) return max(nums[index], nums[index-1]);
        if(dp[index]!=-1) return dp[index];
        int take = nums[index] + solve(index-2, nums, dp); 
        int notake =  solve(index-1, nums, dp);
        return dp[index] = max(take,notake);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1,-1);
        return solve(nums.size()-1,nums,dp);
    }
};
