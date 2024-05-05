/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* temp = node->next;
        ListNode* prev = node;
        while (temp->next != NULL) {
        
            prev->val = temp->val;
            temp = temp -> next;
            prev = prev -> next;
        }
        prev ->val = temp->val;
        prev->next = NULL;

    }
};