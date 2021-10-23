#include<stdio.h>
#include<stdlib.h>

struct q{
    int data;
    struct q* next;
};
struct q* front=NULL;
struct q* rear=NULL;

void enqueue(int data){
    struct q* temp = (struct q*)malloc(sizeof(struct q));
    temp->data = data;
    if(temp==NULL){
        printf("Overflow\n");
        return;
    }
    
    if(front==NULL){
        front = rear = temp;
        front->next = NULL;
        rear->next = NULL;
    }
    
    else{
        rear->next = temp;
        rear = temp;
        rear->next = NULL;
    }
}

void dequeue(){
    if(front==NULL){
        printf("Underflow\n");
        return;
    }
    struct q* temp = front;
    front = temp->next;
    free(temp);
}

void disp(){
    struct q* temp = front;
    printf("\nList is: ");
    if(front==NULL){
        printf("Unerflow\n");
        return;
    }
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
}

int main(){
    int size,data;
    printf("Size: ");
    scanf("%d",&size);
    printf("Enter Data\n");
    for(int i=0;i<size;i++){
        scanf("%d",&data);
        enqueue(data);
    }
    disp();
    dequeue();
    disp();
    return 0;
}
