class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int countNodes = 0;
        ListNode* temp = head;
        while(temp != NULL){
            countNodes++;
            temp = temp->next;
        }
        temp = head;
        int ans = 0;
        countNodes--;
        while(countNodes >= 0){
            if(temp->val == 1){
                ans += pow(2, countNodes);
            }
            countNodes--;
            temp = temp->next;
        }
        return ans;
    }
};
