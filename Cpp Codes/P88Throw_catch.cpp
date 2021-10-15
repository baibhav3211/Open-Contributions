#include <iostream>
using namespace std;
//We can throw our class exception also and we can also extend it with built in class exception from c++ if required.
class MyException:public exception{
    public:
    // char* what(){
    //     return "My exception";
    // }
};
//We can also declare what a function is growing to throw.
//Empty bracket throw i.e. throw() means that the function is not going to throw any exception.
int division(int x, int y)
{
    if (y == 0)
    {
        throw 102;
    }
    return x / y;
}
/*
There are 3 types of error-:
SYNTAX ERROR-: Error is writing the code.
LOGICAL ERROR-: Error in logic of the code i,e, not getting desired output
RUNTIME ERROR-: Error occured due to lack of resources here we use the try and catch method because mistake is not from the  side of programmer
it is from the side of user and has occured on runtime.
*/
int main()
{

    int a = 10, b = 0, c;
    try
    {
        //if there is no throw then catch wont work.
        if (b == 1)
        {
            //We can throw any integer value irrespective of the datatype we use, we can also throw class object if required. 
            throw string("Error code-: 101");
        }
        c = division(a, b);
        cout << c;
    }
    // multiple catch bloxks with different dataypes can be declared incase of a conflict.
    catch (int e)
    {
        cout<<"Error code-: "<<e<< endl;
    }
    catch (string e)
    {
        cout<<e<< endl;
    }
    //THis is the catch all block and it must be declared at the end of all the catch blocks because after this no catch block will get
    //executed.
    catch (...)
    {
        cout<<"All other errors will be catched."<< endl;
    }
    cout << "Bye" << endl;
    return 0;

    /*NOTE-: If we are having two classes i.e. parent and child class respectively then in theis case we will firstly declare the catch bleck
    for the child class and then for the parent class.
    For example-:
    try{
    }
    catch(child e){
    }
    catch(parent e){
    }
    */
}