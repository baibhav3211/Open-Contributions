#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPalindrome(int A) {
         if(A<0){
        return false;
    }
    
    unsigned res = 0;
    int x = A;
    while(x){
        int digit = x%10;
        res = res*10 + digit;
        x = x/10;
    }
    
    return A == res;
   }
};
int main() {
	
	int val = 121;
	Solution obj;
	cout<<obj.isPalindrome(val)<<endl;
	cout<<obj.isPalindrome(124)<<endl;
	cout<<obj.isPalindrome(99999)<<endl;
	return 0;
}
