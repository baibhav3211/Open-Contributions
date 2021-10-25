//Program for finding the transpose of a martix in sparse form

#include <stdio.h>
#include <conio.h>
int a[100][100],b[100][100];

void main()
{
int i,m,n,p,q,col,t;
clrscr();
printf("Enter the no. of rows");
scanf("%d", &a[0][0]);
printf("
Enter the no. of cols");
scanf("%d", &a[0][1]);
printf("
Enter the number of non zero terms");
scanf("%d", &a[0][2]);

for(i=1;i<=a[0][2];i++)
{
printf("
Enter the value (that is non zero)");
scanf("%d",&a[i][2]);
printf("
Enter the row  for %d  : ",a[i][2]);
scanf("%d",&a[i][0]);
printf("
Enter the col for %d  : ",a[i][2]);
scanf("%d",&a[i][1]);
}

/* Printing for testing the sparse input */
printf("The martix you entered is 
       
 Row  	 Col 	 Value 	");
for ( i = 0;i <= a[0][2];i++)
{
printf("
 %d 	 %d 	 %d 	 " , a[i][0],a[i][1],a[i][2]);
}

/* Calling function for evaluation of transpose */

m = a[0][0];
n = a[0][1];
t = a[0][2];

b[0][0] = n;
b[0][1] = m;
b[0][2] = t;

q=1;

for( col = 1; col <=n; col++)
{
	for(p = 1; p<=t;p++)
	{
		if(a[p][1] == col)
		{
		b[q][0] = a[p][1];
		b[q][1] =a[p][0];
		b[q][2] = a[p][2];
		q++;
		}
	}
}                  //end of outer for loop

/* Printing the transposed matrix */

getch();
printf("
The Transpose of the above matrix is ");
for ( i = 0;i <= a[0][2];i++)
{
printf("
 %d 	 %d 	 %d 	 " , b[i][0],b[i][1],b[i][2]);
}
getch();
}
