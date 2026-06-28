class Solution {
public:
    bool dfs(vector<vector<int>> &v , vector<int> & vis, int parent, int x){
        vis[x] =1;
        for(auto it: v[x]){
            if(vis[it] == 1 ){
                if(it == parent) continue;
                else return false;
            }
            
            if(!dfs(v,vis,x,it)) return false;
        }
        
        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> v(n);
        vector<int> vis(n,0);
        for(int i=0;i<edges.size();i++){
            v[edges[i][0]].push_back(edges[i][1]);
            v[edges[i][1]].push_back(edges[i][0]);

        };
        if(!dfs(v,vis,-1,0)) return false;
        for(auto it:vis){
            if( it == 0){
                return false;
            }
        }
        return true;
    }
};
