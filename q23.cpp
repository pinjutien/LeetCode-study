/**
23. Merge k Sorted Lists
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

    bool avaiable_node(vector<ListNode*>& lists) {
        int check = 0;
        for (int i =0; i < lists.size(); i++) {
            if (lists[i] != NULL) {
                check =1;
            }
        }
        return (check ==1);
    }

    int current_head_min(vector<ListNode*>& lists) {
        int current_min_index = 0;
        int current_min = 999;
        for (int i =0; i < lists.size(); i++) {
            if ((lists[i] != NULL) && (lists[i]->val < current_min)) {
                current_min_index = i;
                current_min = lists[i]->val;
            }
            
        };
        // remove it from the lists:
        lists[current_min_index] = lists[current_min_index]->next;
        return current_min;
        
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = new ListNode(0);
        ListNode* temp = head;

        bool avaiable_key = avaiable_node(lists);
        while (avaiable_key == true) {
            int values = current_head_min(lists);
            temp -> next = new ListNode(values);
            temp = temp ->next;
            avaiable_key = avaiable_node(lists);
        }
        return head->next;
    }
};