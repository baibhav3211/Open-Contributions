#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,i,j,k;
		vector<int> v1;
		vector<int> v2;
		cin>>n;
		int a[n];
		int e=0,od=0;
		for(int o=0;o<n;o++)
		{
			cin>>a[o];
			if(a[o]%2==0){e++;}
			else{od++;}
		}

		for(int o=0;o<n;o++)
		{
			if(a[o]%2!=0){v1.push_back(a[o]);}
		}
		for(int o=0;o<n;o++)
		{
			if(a[o]%2==0){v2.push_back(a[o]);}
		}
		if(od>2){cout<<"yes"<<endl;
		i=v1[0];j=v1[1];k=v1[2];
		cout<<i<<" "<<j<<" "<<k<<endl;
		}
		else if(e>1 && od>0){
			cout<<"yes"<<endl;
			i=v1[0];j=v2[0];k=v2[1];
			cout<<i<<" "<<j<<" "<<k<<endl;
		}
		else{cout<<"no"<<endl;}

	}
	return 0;
}