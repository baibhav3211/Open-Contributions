#include <iostream>
using namespace std;
#define abc 10
//will check is it is not defined and then will define
#ifndef abc
    #define abc 3
#endif
#define sqr(po) (po*po)

//used to define a function for converting anything which goes in as parameter to string
#define MSG(acv) #acv
//This declaration of const after Display() will lead to the constancy of the variables
//inside the Display() function.
class Demo
{
public:
    int x = 15;
    void Display() const
    {
        // x++; //this will be handled by the compiler and told as an eror
        cout << x << endl;
    }
};

//This define line is used for defining the constants through out the program and that too
//this will execute at compiling time.
int main()
{
    int b = 10;
    int c = 30;
    //By this way the constant can be initialised then constant will be executed at the time of
    //execution of program.
    //THe scope can alco be limited to a block.
    const int a = 10;
    //Now here in this type of declaration the value of b gets fixed or locked but if we write ptr1++ then
    //this will take ptr1 to the next location which means ptr is not locked the value to which this pointer
    //points that is locked.
    int const *ptr1 = &b;
    cout << *ptr1 << endl;
    int y = 20;
    //Clearly visible ptr1 is not const as it is now pointing to y instead of b.
    ptr1 = &y;
    cout << *ptr1 << endl;
    //Now here because of the small difference of star now the pointer value gets fixed that is now
    //there is no change in the value of pointer and it is locked.
    int *const ptr2 = &b;
    cout << *ptr2 << endl;
    //Now here the pointer and the data both are const nothing can be modified everything is locked.
    const int *const ptr3 = &c;
    cout << *ptr3 << endl;
    Demo d1;
    d1.Display();
    cout<<abc<<endl;
    cout<<MSG(Hello)<<endl;
    cout<<sqr(abc)<<endl;
}