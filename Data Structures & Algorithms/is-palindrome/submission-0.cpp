class Solution {
public:
    bool isPalindrome(string s) {
        int i=0;
        int j=s.size();
        for(int i=0;i<s.size();i++){
            s[i]=tolower(s[i]);
        }
        while(i<=j){
            if(!isalnum(s[i])){
                i++;
                continue;
            }
            if(!isalnum(s[j])){
                j--;
                continue;
            }
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
