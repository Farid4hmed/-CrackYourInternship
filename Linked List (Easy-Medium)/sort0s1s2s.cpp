class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        int count0s= 0;
        int count1s= 0;
        int count2s= 0;
    Node* temp = head;
    while(temp!=NULL){
        if(temp->data == 0)count0s++;
        else if(temp->data == 1)count1s++;
        else count2s++;
        temp = temp->next;
    }
    temp = head;
    while(count0s-- && head!=NULL){
        head->data = 0;
        head = head->next;
    }
    while(count1s-- && head!=NULL){
        head->data = 1;
        head = head->next;
    }
    while(count2s-- && head!=NULL){
        head->data = 2;
        head = head->next;
    }
    return temp;
        
    }
};
