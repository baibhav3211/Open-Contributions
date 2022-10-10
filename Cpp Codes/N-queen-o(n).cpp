// CPP code to for n Queen placement
#include <bits/stdc++.h>

#define breakLine cout << "\n---------------------------------\n";
#define MAX 10

using namespace std;

int arr[MAX], no;

void nQueens(int k, int n);
bool canPlace(int k, int i);
void display(int n);

// Function to check queens placement
void nQueens(int k, int n){

	for (int i = 1;i <= n;i++){
		if (canPlace(k, i)){
			arr[k] = i;
			if (k == n)
				display(n);
			else
				nQueens(k + 1, n);
		}
	}
}

// Helper Function to check if queen can be placed
bool canPlace(int k, int i){
	for (int j = 1;j <= k - 1;j++){
		if (arr[j] == i ||
			(abs(arr[j] - i) == abs(j - k)))
		return false;
	}
	return true;
}

// Function to display placed queen
void display(int n){
	breakLine
	cout << "Arrangement No. " << ++no;
	breakLine

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			if (arr[i] != j)
				cout << "\t_";
			else
				cout << "\tQ";
		}
		cout << endl;
	}

	breakLine
}

// Driver Code
int main(){
	int n = 4;
	nQueens(1, n);
	return 0;
}
