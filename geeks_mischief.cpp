#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &i: a){
        cin>>i;
    }
    set<int> st;
    for(int i=0;i<n;i++){
        st.insert(a[i]);
    }
    vector<int> b;
    for (auto it = st.begin(); it != st.end(); it++){
        b.push_back(*it);
    }
    
    int count=0;
    for(int i=0;i<b.size()-1;i++){
        if(abs(b[i]-b[i+1])==1){
            count++;
        }
    }
    
    if(count==b.size()-1){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
    return 0;
}