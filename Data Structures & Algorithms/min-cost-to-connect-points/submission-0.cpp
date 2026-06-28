class Solution {
public:
    int findDist(int a1, int b1, int a2, int b2){
        return abs(a1-a2) + abs(b1-b2);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dis(points.size(),INT_MAX);
        vector<int> vis(points.size(),0);
        pq.push({0,0});
        int ans=0;
        while(!pq.empty()){
            auto [dist,index] = pq.top();
            pq.pop();
            if(vis[index] ==1) continue;
            vis[index] = 1;
            ans+=dist;
            
            for(int i=0;i<points.size();i++){
                if(i==index || vis[i] == 1) continue;
                int cost = findDist(points[index][0], points[index][1] , points[i][0], points[i][1]);
                if(dis[i] > cost){
                    pq.push({cost, i});
                    dis[i] =cost;
                }
            }
            
        }
        
        
        return ans;
    }
};
