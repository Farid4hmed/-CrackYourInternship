ListNode* middleNode(ListNode* head) {
        if(head->next == NULL)return head;
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast!=0 && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
