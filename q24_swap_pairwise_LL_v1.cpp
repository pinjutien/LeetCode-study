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
    ListNode* swapPairs(ListNode* head) {
        
        if (head == NULL) {
            return head;
        }
        // https://discuss.leetcode.com/topic/18860/7-8-lines-c-python-ruby
        // from :current_ptr = a -> b -> (b->next)
        // to: current_ptr = b -> a -> (b->next)
		
        ListNode **current_ptr = &head, *a, *b;
        while ( (a = *current_ptr)  && ( b = a->next)) {
            a -> next = (b->next);
            b ->next = a;
            *current_ptr = b;
            current_ptr = &(a -> next);
        }
        
        return head;
    }
};