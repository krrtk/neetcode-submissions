class Solution {
public:
    bool dfs(map<int,vector<int>> &mp, vector<bool>& vis,int u,int parent){
        vis[u]=true;
        for(auto &v: mp[u]){
            if(v!=parent && vis[v]){
                return true;
            }
            if(v==parent){
                continue;
            }
            if(dfs(mp,vis,v,u)){
                return true;
            }
        }
        return false;
    }
    bool validTree(int sz, vector<vector<int>>& edges) {
        map<int,vector<int>> mp;
        int n=edges.size();
        if(n==0){
            return true;
        }
        for(int i=0;i<n;i++){
            mp[edges[i][0]].push_back(edges[i][1]);
            mp[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> vis(sz,false);
        if(!vis[edges[0][0]] && dfs(mp,vis,edges[0][0],-1)){
            return false;
        }
        for(int i=0;i<sz;i++){
            cout<<i<<" "<<vis[i]<<endl;
            if(vis[i]==false){
                return false;
            }
        }
        return true;
    }
};
