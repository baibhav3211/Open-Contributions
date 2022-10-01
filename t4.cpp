#include<bits/stdc++.h>
using namespace std;
#define int long long

//subsequence of array
void subs(int i, vector<int> &v, int a[], int n) {
	if (i >= n) {
		for (int y = 0; y < v.size(); y++) cout << v[y] << " ";
		if (v.size() == 0) cout << "{}";
		cout << endl;
		return;
	}

	v.push_back(a[i]);
	subs(i + 1, v, a, n);
	v.pop_back();
	subs(i + 1, v, a, n);

}
bool subs_withsumK(int i, int sum, vector<int> &v, int a[], int n, int k) {
	if (i >= n) {
		if (sum == k)
		{
			for (int y = 0; y < v.size(); y++) cout << v[y] << " ";
			if (v.size() == 0) cout << "{}";
			cout << endl;
			return true;
		}
		else return false;
	}
	if (subs_withsumK(i + 1, sum, v, a, n, k)) return true;
	sum += a[i];
	v.push_back(a[i]);
	if (subs_withsumK(i + 1, sum, v, a, n, k)) return true;
	sum -= a[i];
	v.pop_back();
	return false;

}
int subs_countwithsumK(int i, int sum, int a[], int n, int k) {
	if (i >= n) {
		if (sum == k)
		{
			return 1;
		}
		else return 0;
	}
	int l = subs_countwithsumK(i + 1, sum, a, n, k);
	sum += a[i];
	int r = subs_countwithsumK(i + 1, sum, a, n, k);
	sum -= a[i];
	return l + r;
}
int32_t main() {
	int t, k = 0;
	cin >> t;

	while (t--)
	{
		string s;
		cin >> s;
		int x = s[0] - 'a' + 1,y=s[s.length()-1]-'a'+1;
		vector<pair<int,int>> v;
		for (i = 0; i < s.length (); i++) {
			v.push_back ({s[i] - 'a' + 1,i+1});
		}
		sort (v.begin () , v.end ());
		int cost = 0 , jumps = 0;
		int z = 0;
		for (i = 0; i < s.length (); i++) {
			if (v[i].second > z) {
				cost += abs (v[i].first - x);
				x = v[i].first;
				z = v[i].second;
				jumps++;
			}
			else {
				cost += abs (v[i].first - y);
				while (v[i].first < y) {
					jumps++;
					i++;
				}
			}

			

		}

		// cin >> n >> k;
		// // cout << fibo(n);
		// int a[n];
		// for (int i = 0; i < n; i++) cin >> a[i];
		// vector<int> v;
		// // if (subs_withsumK(0, 0, v, a, n, k)) cout << 1;
		// // else cout << 0;
		// cout << subs_countwithsumK(0, 0, a, n, k);
		// // if (rev(0, a, n)) cout << "YES\n";
		// // else cout << "NO\n";
		// // for (int i = 0; i < n; i++) {
		// // 	cout << a[i] << " ";
		// // }

	}
}