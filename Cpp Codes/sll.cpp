#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int val){
        data=val;
        next = NULL;
    }
};

void insertAtTail(node* &head, int val){

    node* n = new node(val);
    node* temp = head;

    if(head == NULL){
        head = n;
        return;
    }

    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = n;
}

void insertAtHead(node* &head, int val){
    node* n = new node(val);
    n->next = head;
    head = n;
}

bool search(node* head, int key){

    node* temp = head;
    while(temp!=NULL){
        if(temp->data==key){
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void deleteAtHead(node* &head){
    node* todelete = head;
    head = head->next;
    delete todelete;
}

void deletion(node* &head, int val){

    if(head == NULL){
        return;
    }
    if(head->next == NULL){
        deleteAtHead(head);
        return;
    }
    node* temp = head;

    while(temp->next->data!=val){
        temp = temp->next;
    }
    node* todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
}

node* reverseUsingIteration(node* &head){
    node* prev = NULL;
    node* curr = head;
    node* nextp;

    while(curr!=NULL){
        nextp = curr->next;
        curr->next = prev;

        prev = curr;
        curr = nextp;
    }

    return prev;
}

node* reverseUsingRecursion(node* &head){

    if(head == NULL || head->next == NULL){
        return head;
    }
    node* newhead = reverseUsingRecursion(head->next);
    head->next->next = head;
    head->next = NULL;
    return newhead;
}

void display(node* head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    node* head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    insertAtTail(head,6);
    // insertAtHead(head,7);
    display(head);
    
    // cout<<search(head, 16)<<endl;
    // deletion(head,5);
    // deletion(head,4);
    // deletion(head,3);
    // deletion(head,2);
    // deletion(head,1);
    // deletion(head,6);
    // deletion(head,7);
    // display(head);
    // node* newhead = reverseUsingIteration(head);
    node* newhead = reverseUsingRecursion(head);
    display(newhead);
    return 0;
}