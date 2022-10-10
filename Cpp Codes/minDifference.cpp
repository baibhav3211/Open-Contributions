// Given two non-empty array of integers, find the pair of numbers (one from each array) whose absolute diff
// is closest to zero and return the pair containing these two numbers. Only one such pair exists
// a1 = [23,5,10, 17,30]
// a2= [26,134,135, 14,19]

// Output: [17,19]

#include <bits/stdc++.h>
using namespace std;

pair<int, int> minDifference(vector<int> a, vector<int> b){

    sort(b.begin(), b.end());

    int p1,p2;
    int diff = INT_MAX;

    for(int x: a){
        auto lb = lower_bound(b.begin(), b.end(), x) - b.begin();
        if(lb>=1 and x-b[lb-1]<diff){
            diff = x - b[lb-1];
            p2 = b[lb-1];
            p1=x;
        }

        if(lb!=b.size() and b[lb]-x < diff ){
			 		diff = b[lb] - x;
			 		p1 = x;
			 		p2 = b[lb];
		 }
    }
    return {p1,p2};

}

int main(){
    vector<int> a = {23,5,10,17,30};
    vector<int> b = {26,134,135,14,19};
    auto p = minDifference(a,b);
    cout<<p.first<<" "<<p.second<<endl;
    return 0;
}