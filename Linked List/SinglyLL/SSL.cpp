#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data,Node* next) {
        this->data = data;
        this->next = next;
    }
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() {
        this->head = nullptr;
    }

    // Create linked list from vector of integers
    void createLL(vector<int>& values) {
        head = nullptr;  // reset list if any
        Node* mover = nullptr;

        for (int val : values) {
            Node* newNode = new Node(val);

            if (head == nullptr) {
                head = newNode;
                mover = newNode;
            } else {
                mover->next = newNode;
                mover = newNode;
            }
        }
    }

    // Traverse and print the linked list
    void traversal() const {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data;
            if (current->next != nullptr) {
                cout << " -> ";
            }
            current = current->next;
        }
        cout << endl;
    }

    void DeleteAtStart(){
        if(head==nullptr){
            return;
        }
        Node* temp =head;
        head = head->next;
        free(temp);
    }
    
    void DeleteAtEnd(){
        if(head==nullptr){
            return;
        }
        if(head->next == nullptr){
            Node* temp = head;
            head = nullptr;
            free(temp);
            return;
        }
        
        Node* prev = head;
        
        while(prev->next->next){
            prev = prev->next;
        }
        
        Node* temp = prev->next;
        prev->next = temp->next;
        free(temp);
        
        
    }
    
    void DeleteAtPosition(int position){
        if(position == 1 ){
            DeleteAtStart();
            return;
        }
        int positionCount = 1;
        
        Node* prev = head;
        
        while(prev->next){
            positionCount++;
            if(positionCount==position){
               Node* temp = prev->next;
               prev->next = temp->next;
               free(temp);
               return;
            }
            prev = prev->next;
        }
        cout<<"Position is more than the length of the ll"<<endl;
        
    }
    
     void InserAtStart(int element){
        if(head==nullptr){
            head = new Node(element);
            return;
        }
        Node* temp = new Node(element);
        temp->next = head;
        head = temp;
    }
    
    void InserAtEnd(int element){
        if(head==nullptr){
            head = new Node(element);
            return;
        }
        
        Node* mover = head;
        
        while(mover->next){
            mover = mover->next;
        }
        
        mover->next= new Node(element);
    }
    
    void InserAtPosition(int position,int element){
        if(position == 1 ){
            InserAtStart(element);
            return;
        }
        int positionCount = 1;
        
        Node* temp = head;
        
        while(temp){
            positionCount++;
            if(positionCount==position){
                Node* newNode  = new Node(element,temp->next);
                temp->next = newNode;
                return;
            }
            temp = temp->next;
        }
        cout<<"Position is more than the length of the ll"<<endl;
        
    }

    // Destructor to free memory
    ~SinglyLinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
};

// Example usage
int main() {
    SinglyLinkedList sll;
    vector<int> arr = {1, 2, 3, 4, 5};

    sll.createLL(arr);

    cout << "Linked List: ";
    sll.traversal();
    
    cout<<"Adding at the start"<<endl;
    sll.InserAtStart(7);
    sll.DeleteAtStart();
    
    cout << "Linked List: ";
    sll.traversal();
    
    cout<<"Adding at the start"<<endl;
    sll.InserAtEnd(10);
    sll.DeleteAtEnd();
    
    cout << "Linked List: ";
    sll.traversal();
    
    cout<<"Adding at the position "<<10<<endl;
    sll.InserAtPosition(9,8676);
    
    cout << "Linked List: ";
    sll.traversal();
    
    cout<<"Adding  at the position"<<1<<endl;
    sll.InserAtPosition(1,66);
    
    cout << "Linked List: ";
    sll.traversal();
    
    cout<<"Adding at the position"<<4<<endl;
    sll.InserAtPosition(4,66);
   
    cout << "Linked List: ";
    sll.traversal();
    
    sll.DeleteAtPosition(7);
    cout << "Linked List: ";
    sll.traversal();

    return 0;
}