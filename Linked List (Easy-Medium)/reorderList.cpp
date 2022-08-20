class Solution {
public:
    void reorderList(ListNode* head) {
        if(head->next == NULL)return;
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = head;
        ListNode* l1 = head;
        while(fast!=NULL && fast->next != NULL){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = NULL;
        ListNode* l2 = reverse(slow);
        
        merge(l1, l2);
    }
    ListNode* reverse(ListNode* head){
        if(head == NULL || head->next==NULL)return head;
        ListNode* temp;
        ListNode*prev = head;
        ListNode* curr = head->next;
        head->next = NULL;
        while(curr!=NULL){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    void merge(ListNode* l1, ListNode* l2){
        ListNode* temp1;
        ListNode* temp2;
        ListNode* curr1 = l1;
        ListNode* curr2 = l2;
        while(curr1!=NULL){
            temp1 = curr1->next;
            curr1->next = curr2;
            curr1 = temp1;
            if(curr1 == NULL)break;
            temp2 = curr2->next;
            curr2->next = temp1;
            curr2 = temp2;
        }
    }
};
