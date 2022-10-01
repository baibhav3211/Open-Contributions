#include <bits/stdc++.h>
using namespace std;
#define int long long
string convert(string s, int x) {

	int hh = (s[0] - '0') * 10 + (s[1] - '0');
	int mm = (s[3] - '0') * 10 + (s[4] - '0');
	// cout << mm << " " << hh << " ";
	// int y = mm + x;
	hh += x / 60;
	mm += x % 60;

	if (mm >= 60) hh++;
	mm %= 60;
	hh %= 24;

	string p, q;
	// if (mm == 60) {mm = 0; q += "00"; hh++;}
	// if (hh == 24) {hh = 0; p += "00";}
	// if (mm == 60) {mm = 0; q += "00";};
	if (hh / 10 == 0) {
		p += "0";
		p += to_string(hh);
	}
	else {
		p = to_string(hh);
	}
	if (mm / 10 == 0) {
		q += "0";
		q += to_string(mm);
	}
	else {
		q = to_string(mm);
	}
	// cout << p << " " << q << " ";

	for (int i = 0; i <= 1; i++) {
		s[i] = p[i];
	}
	for (int i = 3; i <= 4; i++) {
		s[i] = q[i - 3];
	}
	return s;
}
bool isP(string s) {
	string rev = s;
	reverse(s.begin(), s.end());
	return rev == s;
}
int32_t main ()
{
	// ios_base::sync_with_stdio (false);
	// // cin.tie (NULL);
	// cout << power(12, 21);
	int t;
	cin >> t;
	// cout << t;
	while (t--)
	{
		int n;
		cin >> n;
		int i , a[n] , b[n];
		for (i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (i = 0; i < n; i++) {
			cin >> b[i];
		}
		// vector<pair<int,int>> v1,v2;
		// unordered_multimap<int,int> m1,m2;
		// vector<int> v1,v2;
		unordered_multiset<int> s2;
		multiset<int> s1;
		for (i = 0; i < n; i++) {
			if (b[i] < a[i])
				s2.insert(abs(a[i] - b[i]));
			else
				s1.insert(abs(a[i] - b[i]));
		}
		// sort(v2.begin(),v2.end());
		int days = 0;
		for (auto b : s2) {
			auto it = s1.lower_bound(b);
			if (it != s1.end())
			{
				days++;
				s1.erase(it);
			}
		}
		if (s1.size()>1) days+=s1.size()/2;
		cout << days << endl;
	}
}