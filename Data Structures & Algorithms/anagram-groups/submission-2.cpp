class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& str) {
        vector<vector<string>> ans;
        int k=0;
        vector<bool> vis(str.size(),false);
        for(int i=0;i<str.size();i++){
            if(vis[i]){continue;}
            unordered_map<char,int> mp;
            for(auto x:str[i]){
                mp[x]++;
            }
            vis[i]=true;
            ans.push_back({str[i]});
            for(int j=0;j<str.size();j++){
                if(i!=j){
                    unordered_map<char,int> mp1;
                    for(auto x:str[j]){
                        mp1[x]++;
                    }
                    bool f=true;
                    if(mp.size()!=mp1.size()) {
                        f = false;
                    }
                    else{
                        for(auto x:mp){
                            if(mp[x.first]!=mp1[x.first]){
                                f=false;
                                break;
                            }
                        }
                        if(f){
                            vis[j]=true;
                            ans[k].push_back(str[j]);
                        }
                    }
                }
            }
            k++;
        }
        return ans;
    }
};
