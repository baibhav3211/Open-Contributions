#include<bits/stdc++.h>
using namespace std;
#define int long long

string timeConversion(string s, int m) {
    int hour = (s[0] - '0')*10 + (s[1] - '0');
    int min = (s[3] - '0')*10 + (s[4] - '0');
    hour += m/60;
	min += m%60;
    if (min >= 60){
        hour++;
    }
    min%=60;
    hour%=24;
    
    string a, b;
	if (hour/10 == 0) {
		a += "0";
		a += to_string(hour);
	}
	else {
		a = to_string(hour);
	}
	if (min/10 == 0) {
		b += "0";
		b += to_string(min);
	}
	else {
		b = to_string(min);
	}
	// cout << p << " " << q << " ";

	for (int i = 0; i <= 1; i++) {
		s[i] = a[i];
	}
	for (int i = 3; i <= 4; i++) {
		s[i] = b[i - 3];
	}
	return s;
}

bool isPalindrome(string s){
    string rev=s;
    reverse(s.begin(), s.end());
    return s==rev;
}

int32_t main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        
        int m;
        cin>>s>>m;
        int ans=0;
        if(isPalindrome(s)){
            ans++;
        }
        unordered_set<string> distinct;
        distinct.insert(s);
        while(1){
            s = timeConversion(s, m);
            if(distinct.find(s) != distinct.end()){
                break;
            }
            distinct.insert(s);   
            if(isPalindrome(s)){
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}   