class Solution {
public:
    int dp(int index, vector<int>& cost,vector<int>& v){
        if(index>= cost.size()) return 0;
        if(v[index]!=-1) return v[index];
        int one = dp(index+1,cost,v);
        int two = dp(index+2,cost,v);
        return v[index] = cost[index]+min(one,two);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> v(cost.size() +1,-1);
        return min(dp(0,cost,v),dp(1,cost,v));
        
    }
};
