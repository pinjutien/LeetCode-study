// Merge two sorted linked lists and return it as a new list. The new list should be made // by splicing together the nodes of the first two lists.
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) {return l2;}
        if (l2 == NULL) {return l1;}
        ListNode* head = new ListNode(0);
        ListNode* temp = head;
        while (l1 !=NULL && l2 != NULL) {
            int x1 = l1 -> val;
            int x2 = l2 -> val;
            if (x2 > x1) {
                temp -> next = new ListNode(x1);
                l1 = l1 -> next;
                temp = temp ->next;
            }
            else {
                temp -> next = new ListNode(x2);
                l2 = l2 ->next;
                temp = temp->next;
            }
            
        }

        if (l1 == NULL) {
            temp-> next = l2;
        }
        if (l2 == NULL) {
            temp -> next = l1;
        }
        return head->next;
        
        
    }
};