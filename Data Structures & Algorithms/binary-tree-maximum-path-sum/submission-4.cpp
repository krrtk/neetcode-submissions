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
    int mxx(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int cur=root->val;
        int l=mxx(root->left);
        int r=mxx(root->right);
        maxx=max(maxx,max(cur,max(cur+l,max(cur+l+r,cur+r))));
        return max(cur,max(cur+l,cur+r));
    }
    int maxPathSum(TreeNode* root) {
        int val=mxx(root);
        return maxx;
    }
};
