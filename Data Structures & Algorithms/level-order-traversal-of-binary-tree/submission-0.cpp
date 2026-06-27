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
    // void fn(TreeNode* root,vector<vector<int>> ans, int level){

    // }
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==nullptr){
            return {};
        }
        vector<vector<int>> ans;
        // fn(root,ans,0);
        // return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n =q.size();
            vector<int> curr;
            while(n--){
                TreeNode* front = q.front();
                curr.push_back(front->val);
                q.pop();
                if(front->left){
                    q.push(front->left);
                    
                }
                if(front->right){
                    q.push(front->right);
                }

            }
            ans.push_back(curr);
        }
        return ans;

    }
};
