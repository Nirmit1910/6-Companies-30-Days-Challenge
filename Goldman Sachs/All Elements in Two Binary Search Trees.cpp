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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>ele1,ele2;

        getElements(root1,ele1);
        getElements(root2,ele2);

        int i=0,j=0;
        vector<int>ans;
        while(i<ele1.size() and j<ele2.size())
        {
            if(ele1[i]<ele2[j])
            {
                ans.push_back(ele1[i++]);
            }
            else
            {
                ans.push_back(ele2[j++]);
            }
        }
        while(i<ele1.size())
        {
            ans.push_back(ele1[i++]);
        }
        while(j<ele2.size())
        {
            ans.push_back(ele2[j++]);
        }
        return ans;
    }
    void getElements(TreeNode* root,vector<int>&ele)
    {
        if(root==NULL)
        return;

        getElements(root->left,ele);
        ele.push_back(root->val);
        getElements(root->right,ele);
    }
};