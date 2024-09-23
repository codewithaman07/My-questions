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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head;
        ListNode* fast = head;
        for(int i = 0; i<n; i++){
            fast = fast->next;
        }
        if(fast == nullptr) return head->next;
        while(fast->next != nullptr){
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};

// class Solution {
// public:
//     ListNode* removeNthFromEnd(ListNode* head, int k){
//         ListNode* temp = head;
//         int n = 0;
//         while(temp){
//             n++;
//             temp = temp->next;
//         }
//         temp = head;
//         if(n-k == 0){
//             head = head->next;
//             return head;
//         }
//         for(int i = 1; i<n-k; i++){
//             temp = temp->next;
//         }
//         temp->next = temp->next->next;
//         return head;
  
//     }
// };
