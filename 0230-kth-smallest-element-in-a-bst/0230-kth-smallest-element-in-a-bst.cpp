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
 */class Solution{
    public:
    int kthSmallest(TreeNode* root, int k) {
        return kth_Smallest(root,k);
    }
    int kth_Smallest(TreeNode* root, int &k) {
        if(k==0)
            return -1234;
        if(root->left){
            int res=kth_Smallest(root->left,k); //here the decrement from here effect the original k
            if(k==0)
                return res;
        }

        --k;
        if(k==0)
            return root->val;
        
        if(root->right)
            return kth_Smallest(root->right,k); //here the decrement from here effect the original k

        return -1234;

    }
};