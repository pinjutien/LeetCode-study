/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
      // use hash map to store the address of old linked list
      
        if (head == NULL) return NULL;
        unordered_map<RandomListNode*, RandomListNode*> old2new;
        RandomListNode* old_ptr = head;
        RandomListNode* new_ptr = new RandomListNode(old_ptr->label);

        // initialize the head in hash map
        old2new[head] = new_ptr;
        while (old_ptr) {
            // next ptr
            if (old_ptr->next) {
                // check if next ptr exist in the hash map
                if (old2new.count(old_ptr->next)) {
                    new_ptr->next = old2new[old_ptr->next];
                }
                else {
                    new_ptr->next = new RandomListNode(old_ptr->next->label);
                    old2new[old_ptr -> next] = new_ptr->next;
                }
                
            }
            
            // random ptr
            if (old_ptr->random) {
                
                // check if next ptr exist in the hash map
                if (old2new.count(old_ptr->random)) {
                    new_ptr->random = old2new[old_ptr->random];
                }
                else {
                    new_ptr->random = new RandomListNode(old_ptr->random->label);
                    old2new[old_ptr -> random] = new_ptr->random;
                }
                
            }
            
            old_ptr = old_ptr -> next;
            new_ptr = new_ptr -> next;
        }
        
        return old2new[head];
        
    }
};
