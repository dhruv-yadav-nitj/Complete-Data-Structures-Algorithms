#include <bits/stdc++.h>
using namespace std;

class Test
{
public:
    // constructor
    Test()
    {
        cout << "Hi, I am Constructor." << endl;
    }

    // destructor
    ~Test()
    {
        cout << "Hi, I am Destructor." << endl;
    }
};

int main(int argc, char const *argv[])
{
    Test t1;

    // destructor is used to free the memory
    // a destructor is the last function that is going to be called before an object is destroyed.

    // https://www.geeksforgeeks.org/destructors-c/

    return 0;
}
