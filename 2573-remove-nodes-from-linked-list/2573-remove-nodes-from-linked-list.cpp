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
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*>st;
        ListNode* temp = head;
        while(temp!=NULL){
            st.push(temp);
            temp = temp->next;
        }
        temp = st.top();
        st.pop();
        int maxi = temp->val;
        ListNode* res = new ListNode(temp->val);
        while(!st.empty()){
            temp = st.top();
            st.pop();
            if(maxi>temp->val){
                continue;
            }
            else{
                maxi = temp->val;
                ListNode* newNode = new ListNode(temp->val);
                newNode->next = res;
                res = newNode;
            }
        }
        return res;
    }
};