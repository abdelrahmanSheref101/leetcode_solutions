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
private:
    bool isleaf(TreeNode *node){ return (node && !node->left && !node->right);}
public:
    int sumOfLeftLeaves(TreeNode* root,bool indc=0) {
        if(!root)
            return 0;
        int sum=0;
        if(isleaf(root->left))
            sum+=root->left->val;
        sum +=sumOfLeftLeaves(root->left);
        sum +=sumOfLeftLeaves(root->right);

        return sum;
     
}
};