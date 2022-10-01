#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <limits.h>
// #include <bits/stdc++.h>
using namespace std;
bool f(int x, int y)
{
	return x > y;
}
void vectordemo()
{
	vector<int> A = {2, 3, 11, 14};
	bool pre = binary_search(A.begin(), A.end(), 4);
	if (!pre)
	{
		A.push_back(4);
	}

	A.push_back(100);
	A.push_back(100);
	A.push_back(100);
	A.push_back(100);
	A.push_back(123);
	sort(A.begin(), A.end());

	auto it = lower_bound(A.begin(), A.end(), 100);//O(log n)
	auto it2 = upper_bound(A.begin(), A.end(), 100);
	cout << *it << " " << *it2 << "\n";
	cout << it2 - it << endl;

	sort(A.begin(), A.end(), f);
	for (int &x : A)
	{
		x++;
		// cout << x << " ";
	}
	for (int y : A)
	{
		cout << y << " ";
	}
}
void setdemo()
{
	set<int> s;
	s.insert(0);
	s.insert(-2);
	s.insert(8);
	s.insert(-4);//O(log n)

	for (int x : s)
		cout << x << " ";
	cout << endl;
	auto it = s.find(-1);
	if (it == s.end())
		cout << "not present\n";
	else
	{
		cout << "present\n";
		cout << *it << endl;
	}
	auto it2 = s.upper_bound(-2);//O(log n)
	auto it3 = s.upper_bound(0);
	cout << *it2 << " " << *it3 << "\n";
	auto it4 = s.upper_bound(8);
	//cout << *it4;
	if (it4 == s.end())
	{
		cout << "not found\n";
	}
	s.erase(0);
}
void mapdemo()
{
	map<int, int> A;
	A[1] = 100;
	A[2] = -1;
	A[3] = 6;
	A[756576] = 10;

	map<char, int> cm;
	string x = "ishan agarwal";
	for (char c : x)
	{
		cm[c]++;
	}
	cout << cm['a'] << " " << cm['x'] << endl;
}
void PowerofStl()
{
	//[x,y]
	/*add[2.3]
	add[10,20];
	add[30,400];
	add[401,450];
	give me the interval 401*/
	set<pair<int, int>> S;
	S.insert({401, 450});
	S.insert({10, 20});
	S.insert({2, 3});
	S.insert({30, 400});

	int point = 402;
	auto it = S.upper_bound({point, INT_MAX});
	if (it == S.begin())
	{
		cout << "Not lying in any of the interval\n";
		return;
	}
	it--;
	pair<int, int> current = *it;
	if (current.first <= point && current.second >= point)
	{
		cout << "Yes it's present in interval " << current.first << "," << current.second << endl;
	}
	else
	{
		cout << "Given point is not lying in any of interval\n";
	}



}
int main()
{
	//c++ stl
	PowerofStl();
}