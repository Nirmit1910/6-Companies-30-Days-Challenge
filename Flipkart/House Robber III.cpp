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
    int rob(TreeNode* root) {
        map<TreeNode*,int>m;

        return f(root,m);
    }
    int f(TreeNode* root,map<TreeNode*,int>&m)
    {
        if(root==NULL)
        return 0;

        if(m.find(root)!=m.end())
        return m[root];

        int val=0;
        
        if(root->left)
        val+=f(root->left->left,m)+f(root->left->right,m);

        if(root->right)
        val+=f(root->right->right,m)+f(root->right->left,m);

        val=max(val+root->val,f(root->left,m)+f(root->right,m));

        m[root]=val;
        return val;
    }
};