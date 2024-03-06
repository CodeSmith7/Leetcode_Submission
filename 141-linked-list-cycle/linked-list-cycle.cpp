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
    bool hasCycle(ListNode *head) {
        //slow fast pointer approach 
        // L1 = nk - L2 (that is how this approach works)
        ListNode* slow = head;
        ListNode* fast = head;

        if (head == NULL || head -> next == NULL) {
            return false;
        }
        while (fast != NULL && fast -> next != NULL) {
            slow = slow -> next;
            fast = fast -> next -> next;
            if (slow == fast) {
                return true;
            }
        }
        return false;
    }
};