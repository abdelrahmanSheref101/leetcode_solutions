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
 class Solution{    
     public:    
int goodNodes(TreeNode* root)
{
    if(!root)
        return 0;
    return goodNodes(root,root->val);
}
        int goodNodes(TreeNode* root,int max) {
                int sum=0;
        
                if(!root)
                    return 0;
                if(root->val>=max){
                    ++sum;
                    max=root->val;
                }
                sum+=goodNodes(root->left,max);
                sum+=goodNodes(root->right,max);

                return sum;
        }
};
