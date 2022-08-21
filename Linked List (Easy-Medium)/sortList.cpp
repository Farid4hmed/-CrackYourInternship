class Solution {
public:
    ListNode* sortList(ListNode* head) {
        map<int, int> m;
        ListNode* curr = head;
        while(curr!=NULL){
            m[curr->val]++;
            curr = curr->next;
        }
        curr = head;
        for(auto x: m){
            while(x.second>0){
                curr->val = x.first;
                curr = curr->next;
                x.second--;
            }
        }
        return head;
    }
};
