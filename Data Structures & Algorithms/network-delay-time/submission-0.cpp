class Solution {
public:

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dis(n+1,INT_MAX);
        dis[k]=0;
        pq.push({0,k});
        vector<vector<pair<int,int>>> v(n+1);
        for(auto it: times){
            v[it[0]].push_back({it[1],it[2]});
        };
        
        int total =0;
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            for(auto it: v[top.second]){
                if(dis[it.first] > top.first+it.second)
                {pq.push({top.first+it.second,it.first});
                dis[it.first] =top.first+it.second;}
            }
        }
        for(auto it = 1 ;it<=n  ;it++){
            if(dis[it]==INT_MAX){
                return -1;
            }
            total=max(total,dis[it]);
        }
        return total;

        
    }
};
