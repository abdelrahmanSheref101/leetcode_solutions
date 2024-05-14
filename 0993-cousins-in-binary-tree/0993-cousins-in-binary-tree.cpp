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
    int findNodeDepth(TreeNode *root , int nodeVal ,int depth=0){
        if(!root)
            return 0;
        if(root->val==nodeVal)
            return depth;
        int ldepth=findNodeDepth(root->left,nodeVal,depth+1);
        if(ldepth) 
            return ldepth;
        return findNodeDepth(root->right,nodeVal , depth+1);
             
    }
    TreeNode * findParent(TreeNode *root,int nodeVal){
        if(!root||root->val==nodeVal)
            return nullptr;
        if((root->left&&root->left->val==nodeVal)||(root->right&&root->right->val==nodeVal))
            return root;
        TreeNode *temp=findParent(root->left,nodeVal);
        if(temp)
           return temp; 
        return findParent(root->right,nodeVal);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        if(!root)
            return false;

        if(findNodeDepth(root,x)==findNodeDepth(root,y))
            return (findParent(root,x)!=findParent(root,y));
        return false;
    }        
};