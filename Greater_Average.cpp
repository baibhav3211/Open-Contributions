#include <iostream>
using namespace std;

int main() {
	
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
    {
        float a,b,c;
        cin>>a>>b>>c;
        if(((a+b)/2)>c)
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;
    }
	return 0;
}
