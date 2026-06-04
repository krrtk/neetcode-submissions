class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i]==')'){
                if(!st.empty() && st.top()=='('){
                    st.pop();
                }
                else{
                    st.push(s[i]);
                }

            } 
            else if(s[i]=='}'){

                if(!st.empty() && st.top()=='{'){
                    st.pop();
                }
                else{
                    st.push(s[i]);
                }
            }
            else if(s[i]==']'){
                if(!st.empty() && st.top()=='['){
                    st.pop();
                }
                else{
                    st.push(s[i]);
                }
            }
            else{
                st.push(s[i]);
            }
        }
        // while(!st.empty()){
        //     cout<<st.top();
        //     st.pop();
        // }
        return st.empty()?true: false;
    }
};
