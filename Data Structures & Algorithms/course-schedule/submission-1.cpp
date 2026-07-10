class Solution {
public:
    bool dfs(vector<vector<int>> &mp,vector<bool> &vis,vector<bool> &inrec,int u){
        vis[u]=true;
        inrec[u]=true;
        for(auto& v:mp[u]){
            if(!vis[v] && dfs(mp,vis,inrec,v)){
                return true;
            }
            else if(vis[v] && inrec[v]){
                return true;
            }
        }
        inrec[u]=false;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        vector<bool> vis(n,false);
        vector<bool> inrec(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i] && dfs(adj,vis,inrec,i)){
                return false;
            }
        }
        return true;
    }
};
