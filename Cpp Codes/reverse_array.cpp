#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int N, arr[N];
	for (int i=0;i<N;i++){
	    cin>>arr[i];
	}
	for(int i=N-1;i>=0;i--){
	    cout<<arr[i];
	}
	return 0;
}
