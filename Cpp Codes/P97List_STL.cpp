#include<iostream>
#include<list>
using namespace std;

int main(){
    list<int> v={1,2,2,3};
    v.push_back(25);
    v.push_back(34);
    v.pop_back();
    v.remove(2);
    //Now for iterating throught the value we have two methods 
    //First method using for loop
    for(int x:v){
        cout<<x<<endl;
    }
    //Second method using iterator library.
    list<int>::iterator itr;
    for(itr=v.begin();itr!=v.end();itr++){
        //Here * is used becuase itr works as a pointer to a list.
        cout<<*itr<<endl;
    }
}