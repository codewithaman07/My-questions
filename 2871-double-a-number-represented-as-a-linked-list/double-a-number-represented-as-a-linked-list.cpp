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
    ListNode* doubleIt(ListNode* head) {
        if(!head) return NULL;
        ListNode* temp = head;
        stack<ListNode*>st;
        while(temp){
            st.push(temp);
            temp = temp->next;
        }
        int carry = 0;
        while(!st.empty()){
            ListNode* curr = st.top();
            st.pop();
            int value = curr->val;
            value = value*2 + carry;
            curr->val = (value%10);
            carry = value/10;
        }
        if(carry){
            ListNode* newHead = new ListNode(carry);
            newHead->next = head;
            return newHead;
        }
        return head;
    }
};