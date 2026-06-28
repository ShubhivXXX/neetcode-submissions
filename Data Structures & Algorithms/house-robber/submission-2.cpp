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
        if(nums.size() == 1)
        return nums[0];
        vector<int> dp(nums.size()+1,-1);
        // return solve(nums.size()-1,nums,dp);
        dp[0]  = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(int i=2;i<nums.size();i++){
            int take = nums[i] + dp[i-2]; 
            int notake =  dp[i-1];
            dp[i] = max(take,notake);
        }
        return dp[nums.size()-1];
    }
};
