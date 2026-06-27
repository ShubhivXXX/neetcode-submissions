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
    void fn(TreeNode* root, int maxi, int & count){
        if(root == nullptr){
            return;
        }
        if(root->val >= maxi ){
            count++;
            maxi = root->val;
        }
        fn(root->left,maxi,count);
        fn(root->right,maxi,count);
        return;
    }
    int goodNodes(TreeNode* root) {
        int count = 0;
        fn(root,INT_MIN,count);
        return count;
        
    }
};
