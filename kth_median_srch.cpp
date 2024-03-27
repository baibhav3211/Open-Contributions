#include<iostream>
#include<cmath>
using namespace std;
int median_search(int a[],int l, int r, int k) {
    int ind = r-l+1;
    // pick a random number
    int index = rand() % ind;
    //printf("Index: %d \n", index);
    int i, j=0, m=0, n=0;
    int s1[10],s2[10],s3[10];

    for(i=0; i<=r; i++) {
        if(a[i] < a[index]) {
            s1[j] = a[i];
            j++;
        } else if(a[i] == a[index]) {
            s2[m] = a[i];
            m++;
        } else {
            s3[n] = a[i];
            n++;
        }
    }
    if(j >= k)
        median_search(s1,0,j-1,k);
    else if((j+m) >= k)
        return a[index];
    else
        median_search(s3,0,n-1,k-(j+m));
}

void printArray(int* A, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int A[] = {10, 15, 4, 8, 9, 3, 5, 11, 321, 43, 47, 55, 75, 60};
    printArray(A, sizeof(A)/sizeof(int));
    cout<<"enter nth median to srch"<<endl;
    int k;
    cin>>k;
    int src=median_search(A,0,sizeof(A)/sizeof(int)-1,k);
    cout<<k<<"th median is "<<src<<endl;
    }