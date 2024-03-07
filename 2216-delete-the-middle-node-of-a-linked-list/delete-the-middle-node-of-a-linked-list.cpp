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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;
        if (head == NULL || head -> next == NULL) {
            return NULL;
        }

        while (fast != NULL && fast->next != NULL) {
            prev = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        if (prev != NULL) {
            ListNode* del = slow;
            prev->next = slow->next;
            delete (del);
            return head;
        }
        return head;  
    }
};