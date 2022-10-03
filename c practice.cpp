#include<stdio.h>
int main(){
	
	int number1,number2;
	printf("Enter two num");
	scanf("%d%d",&number1,&number2);
	
	if (number1>number2){
		printf("%d is the largest one", number1);
	}
	
	if (number1<number2){
		printf("%d is the largest one", number2);
	}
	return 0;
}
