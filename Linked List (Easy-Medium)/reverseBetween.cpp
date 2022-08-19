class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
    if(head == NULL) return NULL;
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* pre = dummy; 
    for(int i=0; i<left-1; i++)pre = pre->next;
    
    ListNode* start = pre->next;
    ListNode* after = start->next;
    
    for(int i=0; i<right-left; i++){
        start->next = after->next;
        after->next = pre->next;
        pre->next = after;
        after = start->next;
    }
    
    return dummy->next;
    
    }
};
