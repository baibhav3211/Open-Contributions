#include<iostream>
using namespace std;

class Demo{
    public:
    Demo(){
        cout<<"Constructor of Demo"<<endl;
    }
    ~Demo(){
        cout<<"Destructor of Demo"<<endl;
    }
};

void fun(){
    Demo d;  //OBJECT CREATED IN STACK DELETES AUTOMATICALLY
}

void fun_dynamic(){
    //Dynamic creation of object , if only this is done and fun_dynamic() is called we will get only sonstructor 
    //message as this will not get destroyed untill we call delete function which activates the destructor.
    Demo *p=new Demo(); //OBJECT CREATED IN HEAP HAS TO BE DELETED BY US MANUALLY
    delete p;
}

int main(){
    //Now on calling function we will get both the messages from Constructor and destructor of demo because at 
    //the end of fun() the object is destroyed also
    fun();
    fun_dynamic();
}