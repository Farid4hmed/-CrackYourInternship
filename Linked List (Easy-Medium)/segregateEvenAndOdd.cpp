class Solution{
public:
    Node* divide(int N, Node *head){
        Node* l1 = new Node(0);
        Node* l2 = new Node(0);
        Node* ptr1 = l1;
        Node* ptr2 = l2;
        Node* curr = head;
        while(curr!=NULL){
            if(curr->data%2 == 0){
                Node* temp = new Node(curr->data);
                l1->next = temp;
                l1 = temp;
            }
            else{
                Node* temp = new Node(curr->data);
                l2->next = temp;
                l2 = temp;
            }
            curr = curr->next;
        }
        l1->next = ptr2->next;
        return ptr1->next;
    }
};
