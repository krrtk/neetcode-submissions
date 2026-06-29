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

class Solution {
public:
    bool validate(TreeNode* root, long long maxx,long long minn){
        if(root==NULL){
            return true;
        }
        if(root->val>=maxx || root->val<=minn){
            return false;
        }
        return validate(root->left,root->val,minn) && validate(root->right,maxx,root->val);
    }
    bool isValidBST(TreeNode* root){
        return validate(root,LLONG_MAX,LLONG_MIN);
    }
};
