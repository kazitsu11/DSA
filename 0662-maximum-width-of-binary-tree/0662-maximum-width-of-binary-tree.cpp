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
    int widthOfBinaryTree(TreeNode* root) {
        
        queue<pair<TreeNode*,long long>>q;
        long long ans=0;
        TreeNode* node=root;
        
        if(node==NULL){
            return 0;
        }
        q.push({node,0});
        

        while(!q.empty()){
            int n=q.size();
            long long first=q.front().second;
            long long last;
       while(n--){
            auto[node,index]=q.front();
            q.pop();
            index-=first;
            last=index;

            if(node->left!=NULL){
                q.push({node->left,2*index+1});
            }
            if(node->right!=NULL){
                q.push({node->right,2*index+2});
            }
        }
        ans=max(ans,last+1);
        }
          return ans;
    }
};