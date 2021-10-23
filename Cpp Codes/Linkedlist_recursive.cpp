#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};
Node* head = NULL;

Node* addNode(Node* node, int data){
    Node* temp = new Node();
    temp->data = data;
    if (node != NULL) temp->next = node->next;
    temp->next = NULL;
    return temp;
}

void insert(Node* node, int data){
    if(head == NULL){
        head = addNode(head, data);
        return;
    }
    if(node->next == NULL){
        node->next = addNode(node->next, data);
        return;
    }
    else
        insert(node->next, data);
}

void insert_at_start(int data){
    Node* temp = new Node();
    temp->data = data;
    temp->next = head;
    head = temp;
    return;
}

void insert_at_index(Node* node, int index, int data){
    if(head == NULL || index == 1){
        Node* temp = new Node();
        temp->data = data;
        temp->next = head;
        head = temp;
        return;
    }
    if(index-1 == 1){
        Node* temp = new Node();
        temp->data = data;
        temp->next = node->next;
        node->next = temp;
        return;
    }
    insert_at_index(node->next, index-1, data);
}

void displaylist(Node* node){
    if(head == NULL){
        cout<<"List is empty."<<endl;
        return;
    }
    else if(node == NULL){
        cout<<"NULL"<<endl;
        return;
    }
    else
        cout<<node->data<<"->";
    displaylist(node->next);
}

int main(){
    int size, data;
    cout<<"Number of nodes: "; cin>>size;
    if(size > 0){
        cout<<"Enter Node Data: ";
    }
    for(int i=0; i<size; i++){
        cin>>data;
        insert(head, data);
    }
    displaylist(head);
    
    cout<<"Data to insert at start: "; cin>>data;
    insert_at_start(data);
    displaylist(head);
    
    insert_at_index(head, 1, -1);
    displaylist(head);
    return 0;
}
