class Solution {
public:
    int n,m;
    void bfs(vector<vector<int>>& grid,vector<vector<int>>& dp,int i,int j,int minn){
        dp[i][j]=minn;
        vector<pair<int,int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
        for(int k=0;k<4;k++){
            int ni=i+dir[k].first;
            int nj=j+dir[k].second;
            if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                if(grid[ni][nj]==1 && minn+1< dp[ni][nj]){
                    bfs(grid,dp,ni,nj,minn+1);
                }
            }
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,INT_MAX));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    bfs(grid,dp,i,j,0);
                }
            }
        }
        int maxx=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dp[i][j]==INT_MAX && grid[i][j]==1){
                    return -1;
                }
                if(dp[i][j]!=INT_MAX){
                    maxx=max(maxx,dp[i][j]);
                }
            }
        }
        return maxx;
    }
};
