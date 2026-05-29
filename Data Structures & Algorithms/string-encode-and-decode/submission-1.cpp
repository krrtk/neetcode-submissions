class Solution {
public:

    string encode(vector<string>& str) {
        string s="";
        for(int i=0;i<str.size();i++){
            s+=str[i]+"`";
        }
        return s;
    }

    vector<string> decode(string s) {
        vector<string> str;
        string temp="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='`'){
                str.push_back(temp);
                temp="";
                continue;
            }
            temp+=s[i];
        }
        return str;
    }
};
