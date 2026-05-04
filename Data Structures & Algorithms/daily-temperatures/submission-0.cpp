class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        vector<int> ans(temp.size(),0);
        stack<int>s;
        int i=0;
        while(i<temp.size()){
            
            while(!s.empty() && temp[s.top()]<temp[i]){
                ans[s.top()] = i-s.top();
                s.pop();
            }
            if(s.empty() || (!s.empty() &&temp[s.top()]>=temp[i])){
                s.push(i);
                // i++;
                // continue;
            }
            i++;
        }
        return ans;
        
    }
};
