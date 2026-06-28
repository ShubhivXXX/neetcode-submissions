class Solution {
public:
    int findPar(vector<int> &parent,int node){
        if(parent[node] == node) return node;
        return parent[node] = findPar(parent,parent[node]);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n= edges.size();
        vector<int> parent(n+1);
        vector<int> size(n+1,0);
        for(auto i = 0;i<=n;i++){
            parent[i]=i;
        }   
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            int up = findPar(parent,u);
            int vp = findPar(parent,v);

            if(up == vp){
                return it;
            }
            if(size[up]>size[vp]){
                parent[vp] = up;
            }
            else if(size[up]<size[vp]){
                parent[up] = vp;
            }else{
                parent[up] = vp;
                size[vp]++;
            }
        }
        return {};
    }
};
