class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* node1 = new ListNode(0);
        ListNode* node2 = new ListNode(0);
        ListNode* ptr1 = node1;
        ListNode* ptr2 = node2;
        ListNode* curr = head;
        while(curr!= NULL){
            if(curr->val < x){
                ListNode* temp = new ListNode(curr->val);
                node1->next = temp;
                node1 = temp;
            }
            else{
                ListNode* temp = new ListNode(curr->val);
                node2->next = temp;
                node2 = temp;
            }
            curr = curr->next;
        }
        node1->next = ptr2->next;
        return ptr1->next;
    }
};
