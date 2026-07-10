class Solution {
public:
    void dfs(map<int,vector<int>> mp,vector<bool> & vis,int u){
        vis[u]=true;
        for(auto &v: mp[u]){
            if(!vis[v]){
                dfs(mp,vis,v);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<bool> vis(n,false);
        map<int,vector<int>> mp;
        for(int i=0;i<edges.size();i++){
            mp[edges[i][0]].push_back(edges[i][1]);
            mp[edges[i][1]].push_back(edges[i][0]);
        }
        int u=0;
        for (int i=0;i<n;i++) {
            if (!vis[i]) {
                u++;
                dfs(mp, vis, i); 
            }
        }
        return u;
    }
};
