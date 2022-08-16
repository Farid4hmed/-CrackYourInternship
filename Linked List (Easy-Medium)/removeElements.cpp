class Solution {
public:
    ListNode* removeElements(ListNode* head, int x) {
        if(head == NULL)return NULL;
        while(head!=NULL && head->val == x)head = head->next;
        ListNode* temp = head;
        while(head!=NULL && head->next!=NULL){
            if(head->next->val == x)head->next = head->next->next;
            else head = head->next;
        }
        return temp;
    }
};
