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

        bool isleaf(TreeNode *node){return node&&!node->left&&!node->right;}

        bool isCompleteTree(TreeNode* root) {
            queue <TreeNode *> qu; 

            qu.push(root);

            int size=1;

            bool complete=1;    

            while (!qu.empty()){
                size=qu.size();
                while(size--){

                    TreeNode *cur=qu.front();
                    qu.pop();

                    if(cur->left){
                        if(!complete)
                            return false;
                        qu.push(cur->left);
                    }else
                        complete=0;
                    if(cur->right){
                        if(!complete)
                            return false;
                        qu.push(cur->right);
                    }else
                        complete=0;
                }
            }
                return 1;
        }
}; 