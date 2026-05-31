class Solution {
public:
    char most(map<char,int> mp){
        map<int,char> mp1;
        int maxx=INT_MIN;
        for(auto x: mp){
            mp1[x.second]=x.first;
            maxx=max(maxx,x.second);
        }
        return mp1[maxx];
    }
    int characterReplacement(string s, int k) {
        int i=0;
        int j=0;
        int n=s.size();
        int rep=0;
        int maxx=0;
        int len=0;
        map<char,int> mp;
        while(i<=j && j<n){
            if(rep>k){
                mp[s[i]]--;
                char m=most(mp);
                len--;
                rep=len-mp[m];
                i++;
            }
            else{
                mp[s[j]]++;
                char m=most(mp);
                len++;
                rep=len-mp[m];
                if(rep<=k)
                    maxx=max(maxx,len);
                j++;
            }
        }
        return maxx;
    }
};
