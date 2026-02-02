#include <iostream>
#include <vector>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int data){
            this->data = data;
            this->next = NULL;
        }

        Node* insertBeg(int x){
            Node* node = new Node(x);
            node->next = this;
            return node;
        }
       
        void insertEnd(int x){
            Node* temp = this;
            Node* node = new Node(x);
            while(temp->next){
                temp = temp->next;
            }
            temp->next = node;
        }
};

void print(Node* head){
    Node* temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main(){
    Node* head = new Node(2);
    head = head->insertBeg(1);
    head->insertEnd(0);
    print(head);
}