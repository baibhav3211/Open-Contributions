#include<iostream>
using namespace std;

void bubblesort(int a[],int n){
    bool flag=0;
    for(int i=0 ; i<n ; i++){
        int ptr=0;
        while(ptr<n-i-1){
            if(a[ptr]>a[ptr+1])
            {
                swap(a[ptr],a[ptr+1]);
                flag=1;
            }
            ptr++;
        }
    }
    if (flag==0)
        cout<<"Already sorted array";
    else
        for(int i=0 ; i<n ; i++)
        cout<<a[i]<<" ";
}

int main(){
    int a[]={3,9,1,0,4,7,5};
    int n=sizeof(a)/sizeof(a[0]);
    bubblesort(a,n);
    return 0;
}
