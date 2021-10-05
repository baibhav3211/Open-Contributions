
#include <iostream>
using namespace std;

void relativeComplement(int arr1[], int arr2[],	int n, int m) {

int i = 0, j = 0;
while (i < n && j < m) {

	
	if (arr1[i] < arr2[j]) {
	cout << arr1[i] << " ";
	i++;

	} else if (arr1[i] > arr2[j]) {
	j++;


	} else if (arr1[i] == arr2[j]) {
	i++;
	j++;
	}
}


while (i < n)
	cout << arr1[i] << " ";
}

// Driver code
int main() {
int arr1[] = {3, 6, 10, 12, 15};
int arr2[] = {1, 3, 5, 10, 16};
int n = sizeof(arr1) / sizeof(arr1[0]);
int m = sizeof(arr2) / sizeof(arr2[0]);
relativeComplement(arr1, arr2, n, m);
return 0;
}
