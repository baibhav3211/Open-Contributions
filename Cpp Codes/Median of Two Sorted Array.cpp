/*
There are two sorted arrays A and B of size m and n respectively.

Find the median of the two sorted arrays ( The median of the array formed by merging both the arrays ).

The overall run time complexity should be O(log (m+n)).

Sample Input:

A : [1 4 5]
B : [2 3]

Sample Output:
3
*/

#include<bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
    int n=A.size(), m=B.size();
    if(!n and !m) return -1;
    if(!n) return (m&1)?B[m/2]*1.0:((B[m/2]+B[m/2-1])*1.0)/2;
    if(n>m) return findMedianSortedArrays(B,A);
    int lo=0, hi=n;
    while(lo<=hi)
    {
        int cut1=(lo+hi)/2;
        int cut2=(n+m)/2-cut1;
        int l1=(cut1==0?INT_MIN:A[cut1-1]);
        int r1=(cut1==n?INT_MAX:A[cut1]);
        int l2=(cut2==0?INT_MIN:B[cut2-1]);
        int r2=(cut2==m?INT_MAX:B[cut2]);
        if(l1>r2) hi=cut1-1;
        else if(l2>r1) lo=cut1+1;
        else return ((n+m)&1)?min(r1,r2)*1.0:((max(l1,l2)+min(r1,r2))*1.0)/2;
    }
}


int main() {
    vector<int> A,B;
    int n,m; cin>>n>>m;
    for(int i=0; i<n; ++i) cin>>A[i];
    for(int j=0; j<m; ++j) cin>>B[j];
    int ans=findMedianSortedArrays(A,B);
    cout<<"The answer is: "<<ans;
    return 0;
}
