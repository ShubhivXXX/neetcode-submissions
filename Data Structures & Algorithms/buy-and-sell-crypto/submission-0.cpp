class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0){
            return 0;
        }
        int currMin=prices[0];
        int maxProfit = 0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]<=currMin){
                currMin = prices[i];
                continue;
            }
            maxProfit = max(maxProfit,prices[i]-currMin);
        }
        return maxProfit;
    }
};
