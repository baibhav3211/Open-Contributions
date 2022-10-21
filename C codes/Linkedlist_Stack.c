#include<stdio.h>
#include<stdlib.h>

struct stack{
    int data;
    struct stack* next;
};
struct stack* top;

//Pushing elements onto stack
void push(int data){
    struct stack* temp = (struct stack*)malloc(sizeof(struct stack));
    if(temp==NULL)
        printf("Overflow\n");
    else{
        temp->data = data;
        temp->next = top;
        top = temp;
    }
}

//Popping element
void pop(){
    if(top==NULL)
        printf("Underflow\n");
    else{
        struct stack* temp = top;
        top = top->next;
        temp->next = NULL;
        printf("Popped element: %d\n",temp->data);
        free(temp);
    }
        
}

//Top element of stack
int peek(){
    if(top==NULL)
        return -9999;
    return top->data;
}

//No. of elements
int count(){
    int count=0;
    struct stack* temp = top;
    while(temp!= NULL){
        count++;
        temp = temp->next;
    }
    return count;
}

//If stack is empty or not
void isstackempty(){
    if(top==NULL)
        printf("Stack is empty\n");
    else
        printf("Stack is not empty\n");
}

//If stack is Full or not
void isfull(){
    struct stack* temp = (struct stack*)malloc(sizeof(struct stack));
    if(temp==NULL)
        printf("Overflow\n");
    else
        printf("Not full\n");
}

//Displaying stack
void disp(){
    if(top==NULL){
        printf("Underflow\n");
        return;
    }
    printf("Stack is\n");
    struct stack* temp = top;
    while(temp!= NULL){
        printf("%d\n",temp->data);
        temp = temp->next;
    }
}

int main(){
    int size, data;
    printf("Size of stack: ");
    scanf("%d",&size);
    for(int i=0;i<size;i++){
        scanf("%d",&data);
        push(data);
    }
    disp();

    pop();
    disp();

    printf("TOP element is: %d\n",peek());
    printf("No. of elements: %d\n",count());
    isstackempty();
    isfull();
}
