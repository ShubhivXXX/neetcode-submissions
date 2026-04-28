class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> inc;
        for(auto it : nums){
            inc[it]++;
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>> > pq;
        for(auto it:inc){
            while(pq.size()>k){
                pq.pop();
                
            }
            
                pq.push({it.second, it.first});

            
        }
        while(pq.size()>k){
                pq.pop();
                
            }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
        
    }
};
