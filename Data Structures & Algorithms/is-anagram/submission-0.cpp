class Solution {
public:
    bool isAnagram(string s, string t) {
        map<int,int> mp;
        map<int,int> mp2;
        if(s.size()!=t.size()){
            return false;
        }
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
            mp2[t[i]]++;
        }
        for(auto x:mp){
            if(mp2[x.first]!=mp[x.first]){
                return false;
            }
        }
        return true;
    }
};
