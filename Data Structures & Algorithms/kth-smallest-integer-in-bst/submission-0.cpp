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
    int t;
    int valid(TreeNode* root, int &k){
        if(root==NULL || k>t){
            return -1;
        }
        int l=valid(root->left,k);
        if(l!=-1){
            return l;
        }
        k++;
        if(k==t){
            return root->val;
        }
        int r=valid(root->right,k);
        return r;
    }
    int kthSmallest(TreeNode* root, int kll) {
        t=kll;
        int k=0;
        return valid(root,k);        
    }
};
