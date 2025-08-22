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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>nums;
        ListNode* temp = head;
        int n = 0;
        while(temp){
            n++;
            nums.push_back(temp->val);
            temp = temp->next;
        }
        vector<int>arr;
        for(int i = 1; i<n-1; i++){
            if((nums[i] > nums[i-1] && nums[i] > nums[i+1]) || (nums[i] < nums[i-1] && nums[i] < nums[i+1])) arr.push_back(i);
        }
        int mini = INT_MAX, maxi = -1;
        if(arr.size() <= 1) return {-1,-1};
        maxi = arr[arr.size()-1]-arr[0];
        for(int i = 1; i<arr.size(); i++){
            mini = min(mini, arr[i]-arr[i-1]);
        }
        return {mini, maxi};
    }
};