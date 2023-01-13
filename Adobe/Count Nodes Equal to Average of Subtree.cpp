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
    int ans=0;
    int averageOfSubtree(TreeNode* root) {
        getAvg(root);

        return ans;
    }

    pair<int,int> getAvg(TreeNode* root)
    {
        if(root==NULL)
        return {0,0};

        int child=0;

        pair<int,int> lsum=getAvg(root->left);
        pair<int,int> rsum=getAvg(root->right);

        int totalChild=1+lsum.second+rsum.second;

        int totalSum=root->val+lsum.first+rsum.first;

        if(totalSum/totalChild==root->val)
        ans++;

        return {totalSum,totalChild};
    }  
};