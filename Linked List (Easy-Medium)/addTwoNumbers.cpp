class Solution {
public:
    ListNode *insertEnd(ListNode *head,int x){
    ListNode *temp=new ListNode(x);
    if(head==NULL)return temp;
    ListNode *curr=head;
    while(curr->next!=NULL){
        curr=curr->next;
    }
    curr->next=temp;
    return head;
}
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode* temp1=l1;
        ListNode* temp2=l2;
        ListNode* head = NULL;
        int curVal = 0;
        while(temp1!=NULL && temp2!=NULL){
            curVal = temp1->val + temp2->val + carry;
            if(carry==1)carry=0;
            if(curVal>9){
                carry = 1;
                curVal -= 10;
            }
        head = insertEnd(head, curVal);
            temp1 = temp1->next;
            temp2 = temp2->next;
     }
        if(temp1!=NULL){
            while(temp1!=NULL){
            curVal = temp1->val + carry;
            if(carry==1)carry = 0;
            if(curVal>9){
                carry = 1;
                curVal -= 10;
            }
            head = insertEnd(head, curVal);
            temp1 = temp1->next;
        }
            if(carry==1)head = insertEnd(head, carry);
        }
        
        else {
            while(temp2!=NULL){
            curVal = temp2->val + carry;
            if(carry == 1)carry--;
            if(curVal > 9){
                curVal -= 10;
                carry = 1;
            }
            head = insertEnd(head, curVal);
            temp2 = temp2->next;
        }
            if(carry==1)head = insertEnd(head, carry);
        }
        return head;
    }
};
