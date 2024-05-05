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
    void BSTtolist(TreeNode *root,vector <int>& vec){
        if(!root)
            return;
        BSTtolist(root->left,vec);
        vec.push_back(root->val);
        BSTtolist(root->right,vec);
    }
    TreeNode *_listToBST(int st,int en,vector<int>& vec){
        if(st>en)
            return nullptr;
        int rootPos=(st+en)/2;
        TreeNode *root=new TreeNode(vec[rootPos]);
        root->left=_listToBST(st,rootPos-1,vec);
        root->right=_listToBST(rootPos+1,en,vec);

        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
         if(!root)
            return nullptr;
        if(!root->left&&!root->right)
            return root;
        vector <int> vec;
        BSTtolist(root,vec);
        return _listToBST(0,vec.size()-1,vec);
    }
};