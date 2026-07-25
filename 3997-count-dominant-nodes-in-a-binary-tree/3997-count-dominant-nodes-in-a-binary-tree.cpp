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
int count=0;
int bestval=INT_MIN;
 int dfs(TreeNode* root){
    if(root==NULL){
        return 0;
    }

    int left=dfs(root->left);
    int right=dfs(root->right);
    int left_right=max(left,right);
    int only_root=root->val;
    int subtree=max(root->val,left_right);

    if(only_root >= subtree){
        count++;
    }
    
    return subtree;
 }
    int countDominantNodes(TreeNode* root) {
        dfs(root);
        return count;
    }
};