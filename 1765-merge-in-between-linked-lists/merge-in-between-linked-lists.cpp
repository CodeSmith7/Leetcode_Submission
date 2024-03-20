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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* tempA = list1;
        ListNode* tempB;
        int i = 0;

        while (i < a - 1) {
            tempA = tempA->next;
            i++;
        }

        tempB = tempA->next;

        while (i < b) {
            ListNode* t = tempB;
            tempB = tempB->next;
            i++;
            delete(t);
        }

        tempA->next = list2;

        ListNode* p = list2;

        while (p->next != NULL) {
            p = p->next;
        }
        p->next = tempB;

        return list1;
    }

};