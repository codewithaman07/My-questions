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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int>st;
        int n = nums.size();
        for(int i = 0; i<n; i++) st.insert(nums[i]);
        ListNode dummy;
        ListNode* curr = &dummy;
        curr->next = head;
        while(curr->next){
            if(st.count(curr->next->val)){
                curr->next = curr->next->next;
            }
            else curr = curr->next;
        }
        return dummy.next;
    }
};