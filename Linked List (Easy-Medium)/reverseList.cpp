class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL)return head;
        ListNode* prev = head;
        ListNode* temp = head->next;
        head->next = NULL;
        head = temp;
        while(head!=NULL){
            temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
        return prev;
        
    }
};
