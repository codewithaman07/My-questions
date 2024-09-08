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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*>arr(k, nullptr);
        ListNode* temp = head;
        int n = 0;
        while(temp){
            n++; 
            temp = temp->next;
        }
        temp = head;
        int x = n/k;
        int r = n%k;
        for(int i = 0; i<k; i++){
            ListNode dummy;
            ListNode* tail = &dummy;
            int size = x;
            if(r>0){
                r--;
                size++;
            }
            for(int j = 0; j<size; j++){
                tail->next = new ListNode(temp->val);
                tail = tail->next;
                temp = temp->next;
            }
            arr[i] = dummy.next;
        }
        return arr;
    }
};