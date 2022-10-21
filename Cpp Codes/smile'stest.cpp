#include<bits/stdc++.h>
using namespace std;
long mysqrt(long x)
{
        long s = 0;
        long e = x;
        long ans = 0;     
        
        while(s <= e){
            
            long mid = (s+e)/2;
          
            
            if(1ll*mid*mid == x){
                return mid;
            }else if(1ll*mid*mid < x){ 
                s = mid+1;
                ans = mid;
            }else{
                e = mid - 1;
            }
        }
        
        return ans;
}
long totalTriplets (long n)
{
    return (mysqrt(2*n-1)-1)/2;
}

int main(){
    int t;
    cin>>t;
    while(t--)
    {
        long n;
        cin>>n;
        cout<<totalTriplets(n)<<endl;

    }
    return 0;
}