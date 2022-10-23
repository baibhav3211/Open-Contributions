// C++ implementation of Naive method to print all
// divisors
#include <iostream>
using namespace std;

// function to print the divisors
void printDivisors(int n)
{
	for (int i = 1; i <= n; i++)
		if (n % i == 0)
			cout <<" " << i;
}

/* Driver program to test above function */
int main()
{
	cout <<"The divisors of 100 are: \n";
	printDivisors(100);
	return 0;
}


