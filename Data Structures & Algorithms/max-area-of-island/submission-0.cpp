class Solution {
public:
    void dfs(vector<vector<int>>& grid, int a, int b, int &c) {


        int n = grid.size();
        int m = grid[0].size();
        if(a>=n || b>=m || a<0 || b<0 ){
            return;
        }
        if(grid[a][b]==1){
            c++;
        }
        grid[a][b] = 2;
        if(a-1 >= 0 && grid[a-1][b] == 1){
            dfs(grid,a-1 , b, c);
            
        }
        if(b-1>= 0 && grid[a][b-1] == 1){
            dfs(grid,a ,b-1 , c);
        }
        if(a+1<n && grid[a+1][b] == 1){
            dfs(grid,a+1 ,b, c );
        }
        if(b+1 < m && grid[a][b+1] == 1) {
            dfs(grid,a ,b+1 , c);
        }
        return;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int count=0;
        
        for(int i=0;i<grid.size();i++){
            for(int j = 0 ;j<grid[0].size();j++){
                if(grid[i][j] == 1){
                    int c = 0;
                    dfs(grid,i , j, c);
                    count  = max(count , c);
                }
            }
        }
        return count;
    }
};
