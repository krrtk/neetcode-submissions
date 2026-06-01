class Solution {
public:
    bool chk(map<char,int> cnt,map<char,int>mp){
        for(auto x: mp){
            if(cnt[x.first]<x.second){
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        map<char,int> mp;
        map<char,int> mp1;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        for(int i=0;i<t.size();i++){
            mp1[t[i]]++;
            if(mp[t[i]]==0){
                return "";
            }
        }
        int i=0;
        int j=0;
        map<char,int> cnt;
        bool f=false;
        int len=INT_MAX;
        string res="";
        while(j<s.size() || chk(cnt,mp1)){
            f=chk(cnt,mp1);
            if(!f&& j < s.size()){
                cnt[s[j]]++;
                j++;
            }
            else if (f){
                if(len>j-i){
                    res=s.substr(i,j-i);
                    len=j-i;
                }
                cnt[s[i]]--;
                i++;
            }
            else{
                break;
            }
        }
        return res;
    }
};
