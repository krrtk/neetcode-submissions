/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root){
            return "null";
        }
        string g;
        queue<TreeNode*> q;
        q.push(root);
        g+=to_string(root->val)+',';
        while(!q.empty()){
            TreeNode* temp=q.front();
            q.pop();
            if(temp->left){
                q.push(temp->left);
                g+=to_string(temp->left->val)+',';
            }
            else{
                g+="null,";
            }
            if(temp->right){
                q.push(temp->right);
                g+=to_string(temp->right->val)+',';
            }
            else{
                g+="null,";
            }
        }
        return g;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        string temp="";
        vector<int> vec;
        for(int i=0;i<data.size();i++){
            if(data[i]==','){
                if(temp=="null"){
                    vec.push_back(-1001);
                }
                else{
                    vec.push_back(stoi(temp));
                }
                temp="";
            }
            else{
                temp+=data[i];
            }
        }
        if (vec.empty() || vec[0] == -1001){
            return NULL;
        }
        TreeNode* root = new TreeNode(vec[0]);
        queue<TreeNode*> q;
        q.push(root);
        int i = 1;
        while(!q.empty() && i<vec.size()){
            TreeNode* parent=q.front();
            q.pop();

            if (vec[i]!=-1001) {
                parent->left = new TreeNode(vec[i]);
                q.push(parent->left);
            }
            i++; 
            if(i<vec.size() && vec[i]!=-1001){
                parent->right = new TreeNode(vec[i]);
                q.push(parent->right);
            }
            i++;
        }
        return root;
    }
};
