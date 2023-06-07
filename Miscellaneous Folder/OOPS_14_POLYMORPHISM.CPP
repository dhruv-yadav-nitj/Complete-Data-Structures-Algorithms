// See that part of video

// Runtime Polymorphism
#include <bits/stdc++.h>
using namespace std;

class Animal
{
public:
    void Speaking()
    {
        cout << "Speaking" << endl;
    }
};

// Conditions for Runtime Polymorphism or Dynamic Polymorphism
// Virual Function
// 1. Function name and parameters should be same.
// 2. Inheritance is necessary

class Dog : public Animal
{
public:
    void Speaking()
    {
        cout << "Barking" << endl;
    }
};

int main(int argc, char const *argv[])
{
    Dog d1;
    d1.Speaking(); // this line would print Barking and not Speaking

    // now comment Line 22 and see the difference
    return 0;
}
