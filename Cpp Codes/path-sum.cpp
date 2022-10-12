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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            TreeNode* temp=q.front();
            int x=temp->val;
            
            for(int i=0;i<n;i++)
            {
                temp=q.front();
                q.pop();
                x=temp->val;
                if(!temp->left && !temp->right && x==targetSum) return true;
                if(temp->left)
                {
                    temp->left->val+=x;
                    q.push(temp->left);
                }
                if(temp->right)
                {
                    temp->right->val+=x;
                    q.push(temp->right);
                }
            }
        }
        return false;

    }
};
