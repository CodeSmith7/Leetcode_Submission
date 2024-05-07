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
    ListNode* doubleIt(ListNode* head) {
        ListNode* temp = head;

        stack<ListNode*> st;

        while (temp != NULL) {
            st.push(temp);
            temp = temp -> next;
        }
        int carry = 0;
        while (!st.empty()) {
            ListNode* t = st.top();
            int val = t->val;
            val *= 2;
            t->val = val%10 + carry; 
            carry = val /10;

            st.pop();
        }
         
        if (carry == 1) {
            ListNode* newHead = new ListNode(1);
            newHead -> next = head;
            return newHead;
        }
        
        return head;
    }
};