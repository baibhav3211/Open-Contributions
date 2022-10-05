    #include <bits/stdc++.h> // header file includes every Standard library
    using namespace std;


    int main() {

        // Your code here
        long long t;
        cin>>t;
        while(t--){
            long long x,y,z;
            cin>>x>>y>>z;
            long long st1 = z-x;
            long long st2 = z-y;
            if(st1>st2){
                cout<<st1<<endl;
            }
            else{
                cout<<st2<<endl;
            }
        }
        
        return 0;
    }