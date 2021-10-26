#include<stdio.h>
#include<string.h>

int size, top = -1;
char stack[20];
char postfix[20];
int j=0;

//Pushing the element
void push(char ch){
    top = top+1;
    stack[top] = ch;
}

//Top element
char peek(){
    if(top==-1)
        printf("Underflow\n");
    else
        return stack[top];
}


//Popping the element
char pop(){
    return stack[top--];
}

//If stack is empty or not
int isStackEmpty(){
    if(top == -1)
        return -1;
    return 0;
}

//Deciding the precedence
int Prec(char ch){
    switch (ch){
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return -1;
}

//Infix to Postfix expression
void intopost(char* infix){
    for(int i=0; i<size; i++){
            if(infix[i] >= 'a' && infix[i] <= 'z' || infix[i] >= 'A' && infix[i] <= 'Z')  //If it's an operand
                postfix[j++] = infix[i];
            
            else if(infix[i] == '(')                 // If it is what it is
                push(infix[i]);

            else if(infix[i] == ')'){                // If it is what it is
                    while(peek() != '(')
                        postfix[j++] = pop();
                    pop();
            }

            else{                                    // If it's not what we thought it was
                while( !isStackEmpty() && (Prec(infix[i]) <= Prec(peek())))
                    postfix[j++] = pop();
                push(infix[i]);
            }
    }
    while(!isStackEmpty())
        postfix[j++] = pop();
}

int main(){
    char infix[20];
    printf("Infix Expression: ");
    scanf("%s", infix);
    size = strlen(infix);
    intopost(infix);
    printf("Postfix Expression: %s\n",postfix);
    return 0;
}
