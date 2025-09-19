/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        unordered_map<Node*, Node*>mp;
        Node* newHead = new Node(head->val);
        Node* newTemp = newHead;
        Node* temp = head;
        while(temp){
            if(temp == head){
                mp[temp] = newHead;
                temp = temp->next;
                continue;
            }
            Node* newNode = new Node(temp->val);
            mp[temp] = newNode;
            temp = temp->next;
            newTemp->next = newNode;
            newTemp = newTemp->next;
        }
        temp = head;
        newTemp = newHead;
        while(temp){
            newTemp->random = mp[temp->random];
            newTemp = newTemp->next;
            temp = temp->next;
        }
        return newHead;
    }
};