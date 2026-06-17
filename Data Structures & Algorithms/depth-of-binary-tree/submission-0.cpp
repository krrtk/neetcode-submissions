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
    int maxx=INT_MIN;
    void help(TreeNode* root,int d){
        if(root==NULL){
            maxx=max(d,maxx);
            return;
        }
        maxx=max(d,maxx);
        help(root->left,d+1);
        help(root->right,d+1);
    }
    int maxDepth(TreeNode* root) {
        help(root,0);
        return maxx ;
    }
};
