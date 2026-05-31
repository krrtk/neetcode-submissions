class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> mp;
        int n=s.size();
        int i=0;
        int j=0;
        int len=0;
        while(i<=j && j<n){
            if(i==j || mp[s[j]]==0){
                mp[s[j]]++;
                len=max(len,j-i);
                j++;
            }
            if(mp[s[j]]>=1){
                len=max(len,j-i);
                mp[s[i]]--;
                i++;
            }
        }
        len=max(len,j-i);
        return len;
    }
};
