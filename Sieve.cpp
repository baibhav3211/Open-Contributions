#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N=1e7+10; 
    vector<bool> isPrime(N,1);
    isPrime[0] = isPrime[1] = false;
    
    for(int i=2;i<N;i++)
    {
        if(isPrime[i]==true)
        {
            for(int j=2*i;j<N;j+=i)
            {
                isPrime[j]=false;
            }
        }
    }
    for(int i=1;i<11;i++)
    {
        cout<<isPrime[i]<<endl;
    }
}