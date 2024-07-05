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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* prev =  head;
        ListNode* curr = head->next;
        int pos = 1;
        int mini = INT_MAX;
        int maxi;
        int firstCriticalPos = 0;
        int prevCriticalPos  = 0;

        while ( curr -> next != NULL) {

            if ( (curr->next->val < curr->val && prev -> val < curr-> val ) || (curr->next->val > curr->val && prev -> val > curr-> val )  ) {
                
                if (prevCriticalPos == 0) {
                    firstCriticalPos = pos;
                    prevCriticalPos = pos; 
                } else {
                    mini = min (mini, pos - prevCriticalPos);
                    prevCriticalPos = pos;
                }

            }

            pos++;
            curr = curr -> next;
            prev = prev -> next;

        }

        if (mini == INT_MAX )  
           return {-1,-1}; 
        
        return {mini, prevCriticalPos - firstCriticalPos};
    }
};