class Solution {
public:
    void dfs(vector<vector<char>>& grid, int a, int b){


        int n = grid.size();
        int m = grid[0].size();
        if(a>=n || b>=m || a<0 || b<0 ){
            return;
        }
        grid[a][b] = '2';
        if(a-1 >= 0 && grid[a-1][b] == '1'){
            dfs(grid,a-1 , b);
        }
        if(b-1>= 0 && grid[a][b-1] == '1'){
            dfs(grid,a ,b-1 );
        }
        if(a+1<n && grid[a+1][b] == '1'){
            dfs(grid,a+1 ,b );
        }
        if(b+1 < m && grid[a][b+1] == '1') {
            dfs(grid,a ,b+1 );
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        for(int i=0;i<grid.size();i++){
            for(int j = 0 ;j<grid[0].size();j++){
                if(grid[i][j] == '1'){
                    dfs(grid,i , j);
                    count++;
                }
            }
        }
        return count;
    }
};
