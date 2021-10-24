#include<stdio.h>
#include<string.h>
#include<ctype.h>

int size, top = -1;
char stack[20];

//Pushing the element
void push(char ch){
    top = top+1;
    stack[top] = ch;
}

//Popping the element
char pop(){
    return stack[top--];
}

//Operation on Operands
void operation(char ch){
    int val1 = pop();
    int val2 = pop();
    if(ch == '+')
        push(val1 + val2);
    else if (ch == '*')
        push(val1 * val2);
    else if(ch == '-')
        push(val2 - val1);
    else
        push(val2 / val1);
    return;
}

//Postfix Evaluation
int postfixeval(char* postfix){
    
    for(int i=0; i<size ; i++){
        if(isdigit(postfix[i]))
            push(postfix[i] - '0');
        else
            operation(postfix[i]);
    }
    return pop();
}

int main(){
    char postfix[20];
    printf("Postfix expression: ");
    scanf("%s",postfix);
    size = strlen(postfix);
    int result = postfixeval(postfix);
    printf("Result : %d\n",result);
    return 0;
}