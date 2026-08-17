/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
unordered_map<TreeNode*,TreeNode*>parent;
void makePar(TreeNode* root,TreeNode* par){
    if(root==NULL) return;
    parent[root]=par;

    makePar(root->left,root);
    makePar(root->right,root);
}
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        makePar(root,NULL);

        queue<TreeNode*> q;
        map<TreeNode*,bool>vis;
        q.push(target);
        vis[target]=true;
        vector<int> ans;
        if(root==NULL) return {};

            while (k--) {
                int size=q.size();
                while(size--){
                TreeNode* node = q.front();
                q.pop();

                if(node->left!=NULL && !vis[node->left]){
                    q.push(node->left);
                    vis[node->left]=true;
                }
                if(node->right!=NULL && !vis[node->right]){
                    q.push(node->right);
                    vis[node->right]=true;
                }
                if(parent[node]!=NULL && !vis[parent[node]]){
                    q.push(parent[node]);
                    vis[parent[node]]=true;
                }
            }
        }

        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};