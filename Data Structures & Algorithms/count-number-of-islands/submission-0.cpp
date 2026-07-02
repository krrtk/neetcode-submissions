class Solution {
public:
    void bfs(int r, int c,vector<vector<char>>& grid,vector<vector<bool>>& vis){
        int m=grid.size();
        int n=grid[0].size();

        queue<pair<int,int>> q;
        q.push({r,c});
        while(!q.empty()){
            pair<int,int> p=q.front();
            q.pop();
            vector<pair<int,int>> pp={{0,1},{0,-1},{1,0},{-1,0}};
            for(int i=0;i<pp.size();i++){
                int mp=pp[i].first+p.first;
                int np=pp[i].second+p.second;
                if(0<=mp && mp<m && 0<=np && np<n && !vis[mp][np] && grid[mp][np]=='1'){
                    vis[mp][np]=true;
                    q.push({mp,np});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        int island=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    bfs(i,j,grid,vis);
                    island++;
                }
            }
        }
        return island;
    }
};