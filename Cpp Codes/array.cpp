/*Print the N integers of the array in the reverse order, space-separated on a single line.*/

int main() {

int size;
cin>> size;
int arr[size]; 
for (int i=0;i<size; i++){
    cin>>arr[i];
}
for (int i=size-1;i>=0; i--){
    cout<<arr[i]<<" ";
}
return 0;
}
