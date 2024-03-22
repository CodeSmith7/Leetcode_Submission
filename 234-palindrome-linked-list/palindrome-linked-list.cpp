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
   bool isPalindrome(ListNode* head) {

    //step 1: find middle node  
    ListNode *slow = head , *fast = head;
    while (fast && fast->next) {
        slow = slow -> next;
        fast = fast->next->next;
    }
    if (fast != NULL && fast->next == NULL) {
        slow = slow -> next;
    }

    //step 2 : reverse the back half 
    ListNode* prev = NULL;
    while (slow) {
        ListNode* temp = slow->next;
        slow -> next = prev;
        prev = slow ;
        slow = temp;
    }

    //step 3: comparing the elements in two linked list 
    slow = prev; // reset slow to the head of reversed list
    fast = head; // reset fast to the head of original list
    while (slow && fast) {
        if (slow -> val != fast -> val ) {
            return false; 
        }  
        slow = slow -> next;
        fast = fast -> next;
    }
    return true;
}

};