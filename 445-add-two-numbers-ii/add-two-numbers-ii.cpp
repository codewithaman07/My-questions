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
    ListNode* rev(ListNode* head){
        ListNode* temp = head;
        ListNode* prev = NULL;
        while(temp){
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp = rev(l1);
        ListNode* temp2 = rev(l2);
        int sum = 0, carry = 0;
        ListNode* dummy = new ListNode();
        while(temp || temp2){
            if(temp){
                sum+=temp->val;
                temp = temp->next;
            }
            if(temp2){
                sum+=temp2->val;
                temp2 = temp2->next;
            }
            dummy->val = sum%10;
            carry = sum/10;
            ListNode* node = new ListNode(carry);
            node->next = dummy;
            dummy = node;
            sum = carry;
        }
        return carry == 0 ? dummy->next : dummy;
    }
};