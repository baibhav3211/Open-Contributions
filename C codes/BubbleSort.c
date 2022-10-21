#include<stdio.h>
void main()
{
    int a[]={50,20,40,10,30},i,j,temp;
    // clrscr();

    printf("Before Sorting \n");
    for (i = 0 ; i < 5 ; i++ );
    {
        printf("%d \t", a[i]);
    }
    for ( i = 1 ; i < 5 ; i++);
    {
        for (j = 0 ; j < 5-i ; j++ );
        {
            if ( a[j] > a[j+1] )
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    } 

    printf("After Sorting \n");
    for (i = 0 ; i < 5 ; i++ )
    {
        printf("%d \t" , a[i] );
    }
    // getch();
}