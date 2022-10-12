// CPP Program to print all N primes after
// prime P whose sum equals S
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// vector to store prime and N primes
// whose sum equals given S
vector<int> set;
vector<int> prime;

// function to check prime number
bool isPrime(int x)
{
	// square root of x
	int sqroot = sqrt(x);
	bool flag = true;

	// since 1 is not prime number
	if (x == 1)
		return false;

	// if any factor is found return false
	for (int i = 2; i <= sqroot; i++)
		if (x % i == 0)
			return false;

	// no factor found
	return true;
}

// function to display N primes whose sum equals S
void display()
{
	int length = set.size();
	for (int i = 0; i < length; i++)
		cout << set[i] << " ";
	cout << "\n";
}

// function to evaluate all possible N primes
// whose sum equals S
void primeSum(int total, int N, int S, int index)
{
	// if total equals S And
	// total is reached using N primes
	if (total == S && set.size() == N)
	{
		// display the N primes
		display();
		return;
	}

	// if total is greater than S
	// or if index has reached last element
	if (total > S || index == prime.size())
		return;

	// add prime[index] to set vector
	set.push_back(prime[index]);

	// include the (index)th prime to total
	primeSum(total+prime[index], N, S, index+1);

	// remove element from set vector
	set.pop_back();

	// exclude (index)th prime
	primeSum(total, N, S, index+1);
}

// function to generate all primes
void allPrime(int N, int S, int P)
{
	// all primes less than S itself
	for (int i = P+1; i <=S ; i++)
	{
		// if i is prime add it to prime vector
		if (isPrime(i))
			prime.push_back(i);
	}

	// if primes are less than N
	if (prime.size() < N)
		return;
	primeSum(0, N, S, 0);
}

// Driver Code
int main()
{
	int S = 54, N = 2, P = 3;
	allPrime(N, S, P);
	return 0;
}
