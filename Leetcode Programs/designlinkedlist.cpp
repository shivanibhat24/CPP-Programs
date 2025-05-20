class MyLinkedList {
private:
struct Node{
    int val;
    Node* next;
   Node(int value){
    val = value;
    next = NULL;
   }
};
Node* head;
int size;
public:
    MyLinkedList() {
        head = NULL;
        size = 0;
    }    
    int get(int index) {        
        if(index < 0 || index >= size) return -1;
        Node* curr = head;
        for(int i = 0 ; i < index; i++){
            curr = curr -> next;
        }
    return curr -> val;
    }    
    void addAtHead(int val) {
        Node* temp = new Node(val);
        temp -> next = head;
        head = temp;
        size++;
    }    
    void addAtTail(int val) {
        Node* temp = new Node(val);
        if(!head){
            head = temp;
        }
        else{
        Node* tail = head;
        while(tail -> next){
            tail = tail -> next;
        }
        tail -> next = temp;
        }
        size++;
    }    
    void addAtIndex(int index, int val) {        
        if(index < 0 || index > size) return;
        if(index == 0){
            addAtHead(val);
            return;
        }
       if(index == size){
            addAtTail(val);
            return;
        }
        Node* temp = new Node(val);
        Node* curr = head;        
        for(int i = 0; i < index - 1; i++){
            curr = curr -> next;
        }
        temp -> next = curr -> next;
        curr -> next = temp; 
    size++;
    }    
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;
        if(index == 0){
            Node* temp = head;
            head = head -> next;
            delete temp;
        }
        else{        
        Node* curr = head;
        for(int i = 0 ; i < index - 1; i++){
            curr = curr -> next;
        }
            Node* toDelete = curr->next;
            curr->next = toDelete->next;
            delete toDelete;
        }
        size--;
    }
};
