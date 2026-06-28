class Solution {
public:
int solve(int index , vector<int>& nums , vector<int>& dp, int end ){
    if(index>end) return 0;
        if(index==end) return nums[index];
        if(index == end-1) return max(nums[index], nums[end]);
        if(dp[index]!=-1) return dp[index];
        int take = nums[index] + solve( index+2, nums, dp, end); 
        int notake =  solve( index+1, nums, dp, end);
        return dp[index] = max( take, notake);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        vector<int> dp1(n+1,-1);
        vector<int> dp2(n+1,-1);
        int first = solve(0,nums,dp1,n-2); 
        int second = solve(1,nums,dp2,n-1);
        if(first>second ) return first;
        return second;
    }
};
