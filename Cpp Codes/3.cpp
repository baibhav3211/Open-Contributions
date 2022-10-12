#include<iostream>
#include<vector>

#define ll long long int

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll t;
	cin>>t;

	while(t--) {
		ll n, m ,q;

		bool cons = false;

		cin>>n>>m>>q;

		vector<ll> seats(n + 1, 0);
		int sum = 0;

		bool breakk = false;

		while(q--) {
			char ch;
			ll index;

			cin>>ch>>index;

			if(!breakk) {

				if(sum > m) {
					cons = false;
					breakk = true;
					// break;
				}

				else {
					if(ch=='-' && seats[index]==0){
						cons = false;
						breakk = true;
						// break;
					}
					else if(ch=='-' && seats[index]==1){
						cons = true;
						seats[index] = 0;
						sum--;
					}
					else if(ch=='+' && seats[index]==1) {
						cons = false;
						breakk = true;
						// break;
					}
					else if(ch=='+' && seats[index]==0) {
						cons = true;
						seats[index] = 1;
						sum++;
					}
				}
			}

		}

		if(cons) {
			cout<<"Consistent"<<endl;
		}
		else {
			cout<<"Inconsistent"<<endl;
		}

	}

	return 0;
}