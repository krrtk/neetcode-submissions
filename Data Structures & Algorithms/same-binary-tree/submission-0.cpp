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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> q1; 
        queue<TreeNode*> q2; 
        
        q1.push(p);
        q2.push(q);

        while(!q1.empty() && !q2.empty()){
            TreeNode* gg=q1.front();
            TreeNode* gp=q2.front();
            q1.pop();
            q2.pop();
            if (gg==nullptr && gp==nullptr){
                continue;
            }
            if(gg==nullptr || gp==nullptr || gg->val!=gp->val){
                return false;
            }
            q1.push(gg->left);
            q1.push(gg->right);
            q2.push(gp->left);
            q2.push(gp->right);
        }
        return true;
    }
};
