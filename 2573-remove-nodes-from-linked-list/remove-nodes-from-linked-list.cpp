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
    ListNode* removeNodes(ListNode* head) {
        //Approach 1 -> using stack 
        stack<ListNode*> st;
        ListNode* curr = head;

        while (curr != NULL) {
            st.push(curr);
            curr = curr -> next;            
        }

        curr = st.top();
        st.pop();
        int maxNode = curr->val;

        ListNode* resultHead = new ListNode(curr->val);

        while (!st.empty()) {
             
            curr = st.top();
            st.pop();

            if (curr->val < maxNode) {
                continue;
            } else {
                ListNode* newNode = new ListNode (curr->val);
                newNode-> next = resultHead;
                resultHead = newNode;
                maxNode = curr->val;
            }
        }
        return resultHead;
    }
};