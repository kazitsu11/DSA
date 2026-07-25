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
int bestsum=INT_MIN;
int dfs(TreeNode* root){
    if(root==NULL){
        return 0;
    }
    int left=dfs(root->left);
    int right=dfs(root->right);
    int total=root->val+left+right;
    int left_right=max(left,right)+root->val;
    int only_root=root->val;

    bestsum=max({bestsum,total,left_right,only_root});

    return max(left_right,only_root);
}
    int maxPathSum(TreeNode* root) {
    dfs(root);
    return bestsum;
    }
};

