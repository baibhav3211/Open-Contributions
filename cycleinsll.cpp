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

bool detectCycle(node* &head){
    node* slow = head;
    node* fast = head;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(fast == slow){
            return true;
        }
    }
    return false;
}

void makeCycle(node* &head, int pos){
    node* temp = head;
    node* start;
    int count = 1;
    while(temp->next!=NULL){
        if(count==pos){
            start=temp;
        }
        temp=temp->next;
        count++;
    }
    temp->next = start;
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
    display(head);
    // makeCycle(head,3);
    // display(head);
    cout<<detectCycle(head)<<endl;
    
    
    return 0;
}