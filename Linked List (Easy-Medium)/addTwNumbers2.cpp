class Solution {
public:
    ListNode* insertBegin(ListNode* head, int val){
        ListNode* temp = new ListNode(val);
        if(head == NULL)return temp;
        temp->next = head;
        return temp;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> stack1;
        stack<int> stack2;
        ListNode* temp = l1;
        while(temp!=NULL){
            stack1.push(temp->val);
            temp = temp->next;
        }
        temp = l2;
        while(temp!=NULL){
            stack2.push(temp->val);
            temp = temp->next;
        }
        ListNode* head = NULL;
        int carry = 0;
        while(!stack1.empty() && !stack2.empty()){
            int val = stack1.top() + stack2.top() + carry;
            if(carry == 1)carry = 0;
            if(val>9){
                carry = 1;
                val -= 10;
            }
           head = insertBegin(head, val);
            stack1.pop();
            stack2.pop();
        }
        
            while(!stack1.empty()){
            int val = stack1.top() + carry;
            if(carry) carry = 0;
            if(val > 9){
                carry++;
                val -= 10;
            }
            head = insertBegin(head, val);
                stack1.pop();
        }
            while(!stack2.empty()){
            int val = stack2.top() + carry;
            if(carry)carry = 0;
            if(val > 9){
                carry++;
                val -= 10;
            }
            head = insertBegin(head, val);
                stack2.pop();
            }
            if(carry)head = insertBegin(head, carry);
        return head;
    }
};
