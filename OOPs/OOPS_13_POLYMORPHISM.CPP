// Operator Overloading
// https://www.geeksforgeeks.org/operator-overloading-c/
// '+' operator works for adding two numbers in the case of integers and the same'+' operator works for concatenation of two strings. So, when the same operator works as two different functions it is k/a Operator Overloading.

#include <bits/stdc++.h>
using namespace std;

class HelloWorld
{
public:
    int a, b;

    // operator overloading syntax
    void operator+(HelloWorld &obj)
    {
        int val1 = this->a;
        int val2 = obj.a;

        cout << "Output: " << val2 - val1 << endl;
    }

    // overaloading brackets
    void operator()()
    {
        cout << "Hello Brackets " << this->a << endl;
    }
};

int main(int argc, char const *argv[])
{
    HelloWorld obj1, obj2;
    obj1.a = 3;
    obj2.a = 7;
    obj1 + obj2;

    obj1();

    return 0;
}
