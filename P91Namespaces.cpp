#include<iostream>
using namespace std;
//SOmetimes in our program we want define different function that too not within any classes but with same name
//now here the compiler will give an error that we are defining same function so here comes the use of namespace
//we can define the namespace as shown and use them either with scope resolution operator or 
//by statement using namespace <namespace_name>
namespace First{
    void fun(){
        cout<<"First"<<endl;
    }
};

namespace Second{
    void fun(){
        cout<<"Second"<<endl;
    }
};
using namespace First;
int main(){
    fun();
    //using scope resolution
    Second::fun();
}