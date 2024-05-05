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
    void deleteNode(ListNode* node) {
       node->val = node->next->val;
       node->next = node->next->next;

    }
};
/* In this code we have given a particular note and we have to remove it so we just inserted the value of next node and move the next pointer to next to next*/
