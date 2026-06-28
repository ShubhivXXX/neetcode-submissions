class Solution {
public:
    int dp(int n, vector<int> &v){
            if(n==1) return 1;
            if(n==2) return 2; 
            if(v[n]!=-1) return v[n];
            return v[n] = dp(n-1,v) + dp(n-2,v);
    }
    int climbStairs(int n) {
        vector<int> v(n+1,-1);
        return dp(n,v);
        
    }
};
