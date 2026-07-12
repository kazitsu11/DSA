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
    bool isMirror(TreeNode* leftnode,TreeNode* rightnode){
      if(leftnode==NULL && rightnode==NULL){
        return true;
      }
        if(leftnode==NULL || rightnode==NULL){
        return false;
      }

      if(leftnode->val!=rightnode->val){
        return false;
      }
      return isMirror(leftnode->left,rightnode->right) && isMirror(leftnode->right,rightnode->left);
      
    }
    bool isSymmetric(TreeNode* root) {
         if(root==NULL){
        return true;
       }
       TreeNode *leftnode=root->left;
       TreeNode * rightnode=root->right;

      

       return isMirror(leftnode,rightnode);
    }
};