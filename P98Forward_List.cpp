#include<iostream>
#include<forward_list>
using namespace std;

int main(){
    forward_list<int> v={1,2,3};
    v.push_front(25);
    v.push_front(34);
    v.pop_front();
    //Now for iterating throught the value we have two methods 
    //First method using for loop
    for(int x:v){
        cout<<x<<endl;
    }
    //Second method using iterator library.
    forward_list<int>::iterator itr;
    for(itr=v.begin();itr!=v.end();itr++){
        //Here * is used becuase itr works as a pointer to a forward_list.
        cout<<*itr<<endl;
    }
}