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

class Codec {
   public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> q;
        string ans;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node == NULL) {
                ans += "null,";
                continue;
            }
            ans += to_string(node->val) + ",";
            q.push(node->left);
            q.push(node->right);
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "" || data == "null,") return NULL;
        
        vector<string> tokens;
        stringstream ss(data);
        string temp;

        while (getline(ss, temp, ',')) {
            tokens.push_back(temp);
        }
        
        if(tokens.empty() || tokens[0] == "null") return NULL;

        TreeNode* root = new TreeNode(stoi(tokens[0]));
        queue<TreeNode*> q;
        q.push(root);
        int i = 1;

        while (!q.empty() && i < tokens.size()) {
            TreeNode* node = q.front();
            q.pop();

            if (i < tokens.size() && tokens[i] != "null") {
                node->left = new TreeNode(stoi(tokens[i]));
                q.push(node->left);
            }
            i++;
            if (i < tokens.size() && tokens[i] != "null") {
                node->right = new TreeNode(stoi(tokens[i]));
                q.push(node->right);
            }
            i++;
        }
        return root;
    }
};