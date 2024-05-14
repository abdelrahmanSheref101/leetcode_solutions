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
        vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

            vector<vector<int>> resluts ;    

            if(!root)

                return resluts;
            deque <TreeNode *> qu;
            qu.push_back(root);

            int level=0,size=1;

            while(!qu.empty()){

                size=qu.size();

                resluts.push_back(vector<int>(size));
                int cnt=0;
                while(size--){
                    TreeNode *cur;

                    if(level%2==0){
                        cur=qu.front();
                        qu.pop_front();
                        if(cur->left)
                            qu.push_back(cur->left);
                        if(cur->right)
                            qu.push_back(cur->right);
                    }
                    else{
                        cur=qu.back();
                        qu.pop_back();
                        if(cur->right)
                            qu.push_front(cur->right);
                        if(cur->left)
                            qu.push_front(cur->left);
                    }
                    resluts [level][cnt++]=cur->val;
                }
                ++level;
                cout<<"\n";
             }
            return resluts ;
        }
        
};