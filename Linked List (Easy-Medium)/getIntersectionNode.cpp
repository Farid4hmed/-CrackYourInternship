class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if(headA == NULL || headB == NULL) return NULL;
    
    ListNode* i = headA;
    ListNode* j = headB;
    
    while(i != j){
        i = i == NULL? headB : i->next;
        j = j == NULL? headA : j->next;    
    }
    
    return i;
    }
};
