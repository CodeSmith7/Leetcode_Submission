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
    int lengthOfNode(ListNode* head) {
        int count = 0;
        ListNode* temp = head;
        while (temp != NULL) {
            count++;
            temp  = temp->next;
        }
        return count;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //Approach 1 : one pass
        int len = lengthOfNode(head);
        
        if (len == n) {
            ListNode* temp = head->next;
            delete(head);
            return temp;
        }
        
        int front_travel = len - n;
        
        ListNode *prev = NULL;
        ListNode *curr = head;
    
        while ( front_travel-- ) {
           
            prev = curr;
            curr= curr->next;
        }

        prev->next = curr->next;
        delete(curr);
        return head;
    }
};