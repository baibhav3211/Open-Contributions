#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    double solvee(double x, int n){
        if(n==0)
            return 1;
        if(n==1)
            return x;
        
        double u = myPow(x, n/2);
        u = u*u;
        if(n&1){
            
            u = u*x;
           

        }
        
        return u;
    }
    double myPow(double x, int n) {
        
        if(n>=0)
            return solvee(x, n);
        
        return 1.0/solvee(x,abs(n));
        
        
    }
};
int main() {
// 	vector<string> nums = {"flower","flow","flight"};
// 	int val = 121;
	Solution obj;
	cout<<obj.myPow(2.0000,10)<<endl;
	return 0;
}
