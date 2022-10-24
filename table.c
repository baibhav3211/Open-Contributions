// exercise 1 

// alternative solution using do while loop

#include<stdio.h>

void main()
{
    int count;
    int num;
    printf("Enter a number : ");
    scanf("%d", &num);

    for(count=1; count<=10; count++){
        printf("%d X %d = %d \n", num, count, num*count);
    }


}

