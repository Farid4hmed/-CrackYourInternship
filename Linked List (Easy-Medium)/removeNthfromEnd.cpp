class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int countNodes = 0;
        ListNode* curr = head;
        while(curr!= NULL){
            countNodes++;
            curr = curr->next;
        }
        int NodeIdx = countNodes - n;
        
        if(NodeIdx == 0){
            ListNode* newHead = head->next;
            delete(head);
            return newHead;
        }
        curr = head;
        while(NodeIdx>1){
            curr = curr->next;
            NodeIdx--;
        }
        curr->next = curr->next->next;
        return head;
    }
};
