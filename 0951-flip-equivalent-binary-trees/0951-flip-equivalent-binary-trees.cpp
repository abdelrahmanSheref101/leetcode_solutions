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
    string parenthesizing_canonical(TreeNode *root){
        if(!root)
            return "()";
        string str="("+to_string(root->val);
        if(root->left&&root->right){
            if(root->left->val>=root->right->val)
                str+=parenthesizing_canonical(root->right)+parenthesizing_canonical(root->left);
            else
                str+=parenthesizing_canonical(root->left)+parenthesizing_canonical(root->right);
        }else if(root->left&&!root->right)
                str+="()"+parenthesizing_canonical(root->left);
        else if(root->right&&!root->left)
                str+="()"+parenthesizing_canonical(root->right);
        else if(!root->right&&!root->left)
                str+="()()";
        str +=")";
        return str;
    }
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(!root1&&!root2)
            return true;
        if((root1&&!root2)||(!root1&&root2))
            return false;
        return parenthesizing_canonical(root1)==parenthesizing_canonical(root2);
        
    }

};