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
class Solution {
public:
int getLength(ListNode* head){
    int l=0;
    while(head!=NULL){
        head=head->next;
        l++;
    }
    return l;
}
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int L=getLength(head);

        if(L==n){
            ListNode* temp=head->next;
            delete(head);
            return temp;
        }

        ListNode* curr=head;
        ListNode* prev=NULL;

        int travel=L-n;

        while(travel--){
            prev=curr;
            curr=curr->next;
        }

        prev->next=curr->next;
        delete(curr);

        return head;
    }
};