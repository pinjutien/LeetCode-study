/*
 Given a linked list, remove the nth node from the end of list and return its head.
 
 For example,
 
 Given linked list: 1->2->3->4->5, and n = 2.
 
 After removing the second node from the end, the linked list becomes 1->2->3->5. 
 
*/

/*
 //Definition for singly-linked list.
 struct ListNode {
 int val;
 ListNode *next;
 ListNode(int x) : val(x), next(NULL) {}
 };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // use two pointers, p1 and p2.
        // 1. distance between p1 and p2 = n.
        // 2. move p1 and p2 simultaneously until p2->next is NULL;
        // 3. p1 is the element right before the element which we want to remove.
        //    ie. p1->next is the element which we want to remove.
        if (head == NULL) {return head;}
        ListNode* p1= head;
        ListNode* p2= head;
        int i = 0;
        while (i < n && p2 != NULL) {
            p2 = p2-> next;
            i += 1;
        }
        
        // for n >= size of linked-list
        if (p2 ==NULL) {
            head = p1 ->next;
            return head;
        }
        
        while (p2->next != NULL) {
            p1 = p1 -> next;
            p2 = p2 -> next;
        }
        ListNode* temp = p1 -> next;
        p1 -> next = temp -> next;
        delete temp;
        return head;
    }
};