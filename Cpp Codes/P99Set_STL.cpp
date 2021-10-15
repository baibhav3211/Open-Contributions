#include<iostream>
#include<set>
using namespace std;

int main(){
    set<int> v={1,2,3};
    v.insert(25);
    v.insert(25);
    v.insert(34);
    //Now for iterating throught the value we have two methods 
    //First method using for loop
    for(int x:v){
        cout<<x<<endl;
    }
    //Second method using iterator library.
    set<int>::iterator itr;
    for(itr=v.begin();itr!=v.end();itr++){
        //Here * is used becuase itr works as a pointer to a set.
        cout<<*itr<<endl;
    }
}