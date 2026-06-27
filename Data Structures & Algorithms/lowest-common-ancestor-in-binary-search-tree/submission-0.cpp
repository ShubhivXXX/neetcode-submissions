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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr){
            return nullptr;
        }
        if(root==p) return p;
        if(root==q) return q;
        
        TreeNode* left =lowestCommonAncestor(root->left, p, q);
        TreeNode* right =lowestCommonAncestor(root->right, p, q);
        if((left == p && root == q) || (root == p && left == q)|| (root == p && right == q)|| (right == p && root == q)){
            return root;
        }
        if(left && right){
            return root;
        }else if(left){
            return left;
        }
        else if(right){
            return right;
        }
        return nullptr;
        
    }
};
