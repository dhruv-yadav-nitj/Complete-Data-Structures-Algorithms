// https://www.geeksforgeeks.org/cpp-polymorphism/
#include <bits/stdc++.h>
using namespace std;

// Polymorphism --> Compile Time & Runtime
// Compile Time --> Function Overloading & Operator Overloading
// Runtime --> Virtual Functions

// Function Overloading
// https://www.geeksforgeeks.org/function-overloading-c/

class HelloWorld
{
public:
    // first fx with same name
    void fun(int x, int y)
    {
        cout << "Sum is: " << x + y << endl;
    }

    // second fx with same name
    void fun(double x, int y)
    {
        cout << "Double is: " << x << " Integer is: " << y << endl;
    }

    // third fx with same name
    void fun(int y, double)
    {
        cout << "Hello World Finish" << endl;
    }
};

int main(int argc, char const *argv[])
{
    HelloWorld temp1;

    temp1.fun(2, 3);
    temp1.fun(3.0, 2);
    temp1.fun(2, 2.0);

    return 0;
}
