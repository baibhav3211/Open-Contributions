#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> v={1,2,3};
    v.push_back(25);
    cout<<v.at(1)<<endl;
    v.push_back(34);
    v.pop_back();
    cout<<v.size()<<endl;
    //Now for iterating throught the value we have two methods 
    //First method using for loop
    for(int x:v){
        cout<<x<<endl;
    }
    //Second method using iterator library.
    cout<<v.size()<<endl;
    vector<int>::iterator itr;
    for(itr=v.begin();itr!=v.end();itr++){
        //Here * is used becuase itr works as a pointer to a vector.
        cout<<*itr<<endl;
    }
}