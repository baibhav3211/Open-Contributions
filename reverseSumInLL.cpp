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

void insertAtTail1(node* &head1, int val){

    node* n = new node(val);
    node* temp = head1;

    if(head1 == NULL){
        head1 = n;
        return;
    }

    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = n;
}

void insertAtTail2(node* &head2, int val){

    node* n = new node(val);
    node* temp = head2;

    if(head2 == NULL){
        head2 = n;
        return;
    }

    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = n;
}

void insertAtHead1(node* &head1, int val){
    node* n = new node(val);
    n->next = head1;
    head1 = n;
}
void insertAtHead2(node* &head2, int val){
    node* n = new node(val);
    n->next = head2;
    head2 = n;
}

node* reverse(node* &head2){
    if(head2==NULL || head2->next == NULL){
        return head2;
    }
    node* newhead = reverse(head2->next);
    head2->next->next = head2;
    head2->next = NULL;
    return newhead;

}

node* add(node* head1, node* head2){
    node* temp1 = head1;
    node* temp2 = head2;
    while(temp1!=NULL && temp2!=NULL){
        temp1->data = temp1->data + temp2->data;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return head1;
}

void display1(node* head1){
    node* temp = head1;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
void display2(node* head2){
    node* temp = head2;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    node* head1=NULL;
    node* head2=NULL;
    insertAtTail1(head1,1);
    insertAtTail1(head1,2);
    insertAtTail1(head1,3);
    insertAtTail1(head1,4);
    insertAtTail1(head1,5);
    insertAtTail1(head1,6);
    display1(head1);
    insertAtTail2(head2,1);
    insertAtTail2(head2,2);
    insertAtTail2(head2,3);
    insertAtTail2(head2,4);
    insertAtTail2(head2,5);
    insertAtTail2(head2,6);
    // display2(head2);
    node* newhead = reverse(head2);
    display2(newhead);
    head1 = add(head1,newhead);
    display1(head1);
    
    
    return 0;
}