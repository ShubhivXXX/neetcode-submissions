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
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int prestart, int preend,int instart,int inend, map<int,int>& m){
        if(prestart>=preorder.size() ||instart>=inorder.size() || prestart<0 || inend >= inorder.size() || instart<0 || preend<prestart || inend<instart) return nullptr;
        TreeNode * temp = new TreeNode(preorder[prestart]);
        temp->left = solve(preorder,inorder,prestart+1,prestart+1+m[preorder[prestart]] - 1-instart, instart, m[preorder[prestart]] - 1,m);
        temp->right = solve(preorder,inorder,prestart+1+m[preorder[prestart]]-instart,preend,m[preorder[prestart]] + 1, inend,m);
 
        return temp;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>m;
        for(int i=0;i<inorder.size();i++){
            m[inorder[i]] = i;
        }
        TreeNode * root = solve(preorder,inorder,0,preorder.size()-1, 0, inorder.size()-1,m);
        return root;
        
    }
};
