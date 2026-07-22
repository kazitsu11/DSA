/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
TreeNode* tree(vector<int>& arr,int left,int right){
    int mid=left+(right-left)/2;

    if(left>right){
        return NULL;
    }
    TreeNode* root=new TreeNode(arr[mid]);
    root->left=tree(arr,left,mid-1);
    root->right=tree(arr,mid+1,right);
    
    return root;
}
    TreeNode* sortedListToBST(ListNode* head) {
        
        vector<int>arr;
        // if(head==NULL){
        // return new TreeNode(head->val);
        // }
        ListNode* curr=head;

        while(curr!=NULL){
         arr.push_back(curr->val);
         curr=curr->next;
        }

        int left=0;
        int right=arr.size()-1;

      return  tree(arr,left,right);
    }
};