class Solution {
public:
    bool isSameTree(TreeNode* root1, TreeNode* root2){
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        q1.push(root1);
        q2.push(root2);
        while(!q1.empty() && !q2.empty()){
            TreeNode* gg=q1.front();
            TreeNode* gp=q2.front();
            q1.pop();
            q2.pop();
            if (gg==NULL && gp==NULL) {
                continue;
            }
            if (gg==NULL || gp==NULL || gg->val!=gp->val){
                return false;
            }
            q1.push(gg->left);
            q1.push(gg->right);
            q2.push(gp->left);
            q2.push(gp->right);
        }
        return true;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* g=q.front();
            q.pop();
            if(g==NULL){
                continue;
            }
            if(g->val==subRoot->val){
                if(isSameTree(g,subRoot)){
                    return true;
                }
            }
            q.push(g->left);
            q.push(g->right);
        }
        return false;
    }
};