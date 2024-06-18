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
    std::vector<vector<int>> verticalTraversal(TreeNode* root) {
        std::vector<vector<int>> result;

        queue<TreeNode*> q;

        while(!q.empty()){
            int size = q.size();             
            TreeNode* node = q.front();
            q.pop();
            vector<int> row;
            
            for(int i = 0; i < size; i++){
                row.push_back(node->val);

                if(node->left != nullptr){
                    q.push(node->left);
                }

                if(node->right != nullptr){
                    q.push(node->right);
                }
                
            }
            result.push_back(row);
        }

        return result;
    }
};