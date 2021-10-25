#include<stdio.h>

int front=-1, rear=-1,size;

void enqueue(int *queue, int data){
    if(front == 0 && rear == size - 1 || rear == front - 1){
        printf("Oueue is Full\n");
        return;
    }
    if(front == -1){
        front = 0;
        rear = 0;
    }
    else{
        if(rear == size - 1)
            rear = 0;
        else
            rear++;
    }
    queue[rear] = data;
}

int dequeue(){
    if(front == -1){
        print("Queue is empty\n");
        return;
    }
    else{
        
    }
}

void disp(int *queue){
    if(rear>=front){
        for(int i=front;i<=rear;i++)
            printf("%d ",queue[i]);
    }
    else{
        for(int i=front;i<size;i++)
            printf("%d ",queue[i]);
        for(int i=0;i<=rear;i++)
            printf("%d ",queue[i]);
    }
}

int main(){
    int data;
    printf("Size: ");
    scanf("%d",&size);
    int queue[size];
    printf("Enter data\n");
    for(int i=0;i<size;i++){
        scanf("%d",&data);
        enqueue(queue,data);
    }
    disp(queue);
    return 0;
}
