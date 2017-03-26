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
  // ref: http://www.jiuzhang.com/solutions/reverse-linked-list/
    ListNode* reverseList(ListNode* head) {
        ListNode* current = head;
        ListNode* prev = NULL;
        ListNode* temp;
        while(current != NULL) {
            temp = current->next;
            current->next = prev;
            prev = current;
            current = temp;

        }
        
        return prev;
    }







};
