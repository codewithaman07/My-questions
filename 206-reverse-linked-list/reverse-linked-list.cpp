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
    void reverse(ListNode* &head, ListNode* &prev, ListNode* &curr){
        if(curr == nullptr){
            head = prev; 
            return;
        }
        ListNode* front = curr->next;
        reverse(head, curr, front);
        curr->next = prev;
    }
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return nullptr;
        if(head->next == nullptr) return head;
        ListNode* prev = nullptr;
        ListNode* curr = head;
        reverse(head, prev, curr);
        return head;
    }
};