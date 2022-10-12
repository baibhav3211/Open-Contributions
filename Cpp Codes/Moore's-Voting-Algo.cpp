#include<bits/stdc++.h>
using  namespace  std;


//This function returns the index of the element that occurs more than n/2 numbers of times
int MooreVotingAlgo(int arr[],int n)
{
//checks if there is a possibility of element that occurs more than n/2 numbers of times
	int res = 0,count = 1;
	for(int i = 1; i < n; i++)
	{
           if(arr[res] == arr[i]){
           	count++;
           } else {
              count--;
           }

           if(count == 0)
           {
           	 res = i; count = 1;
           }
  	}
    //count the occurrence of possible element
  	count = 0;
  	for(int i =0; i < n;i++)
  	{
  		if(arr[res] == arr[i])
  			count++;
  	}

  	if(count <= (n/2))
  		return -1;
  	return res;
}


int main(){
	int n = 5;
	int a[5] = {8, 3, 4, 8, 8};
     int idx = MooreVotingAlgo(a,n);
	if( idx == -1){
		cout<<"No majority element present in the given array";
	} else {
		cout<<"The majority element in the given array is "<<a[idx];
	}
	
}