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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        
        ListNode* last = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        
        return last;
    }    

    ListNode* removeNodes(ListNode* head) {
        //Approach 1 -> using stack 
        // stack<ListNode*> st;
        // ListNode* curr = head;

        // while (curr != NULL) {
        //     st.push(curr);
        //     curr = curr -> next;            
        // }

        // curr = st.top();
        // st.pop();
        // int maxNode = curr->val;

        // ListNode* resultHead = new ListNode(curr->val);

        // while (!st.empty()) {
             
        //     curr = st.top();
        //     st.pop();

        //     if (curr->val < maxNode) {
        //         continue;
        //     } else {
        //         ListNode* newNode = new ListNode (curr->val);
        //         newNode-> next = resultHead;
        //         resultHead = newNode;
        //         maxNode = curr->val;
        //     }
        // }
        // return resultHead;


        //Approach 2 -> using reecursion 
        // if (head == NULL || head -> next == NULL) {
        //     return head;
        // }
 
        // ListNode* nextNode = removeNodes(head -> next );

        // if (head -> val < nextNode-> val) {
        //     delete head;
        //     return nextNode;
        // }

        // head->next = nextNode;
        
        // return head;

        //Approach 3 : reverse the linked list 

        head = reverseList(head);

        int maximum = 0;
        ListNode* prev = NULL;
        ListNode* current = head;

        while (current != NULL) {
            maximum = max(maximum, current->val);

            if (current->val < maximum) {
                prev->next = current->next;
                ListNode* deleted = current;
                current = current->next;
                delete(deleted);
            }

            else {
                prev = current;
                current = current->next;
            }
        }
        
        return reverseList(head);

     
    }



    
};