class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        queue<int> pq;
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0);
        for(auto it: prerequisites){
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }
        for(auto i = 0 ;i< indegree.size();i++){
            if(indegree[i] ==0){
                pq.push(i);
            }
        }
        int count=0;
        while(!pq.empty()){
            auto top = pq.front();
            count++;
            pq.pop();
            for(auto it:adj[top]){
                indegree[it]--;
                if(indegree[it]==0){
                    pq.push(it);
                }
            }
        }
        if(count==numCourses) return true;
        return false;
    }
};
