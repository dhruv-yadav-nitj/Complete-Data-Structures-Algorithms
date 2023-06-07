#include <bits/stdc++.h>
using namespace std;

class Animal
{
public:
    void barking()
    {
        cout << "Barking" << endl;
    }
};

class Human
{
public:
    void speak()
    {
        cout << "Speaking" << endl;
    }
};

// Mutlilple Inheritance

class Temp : public Animal, public Human
{
public:
};

int main(int argc, char const *argv[])
{
    Temp temp1;

    // the properties of both the classes are inherited in the class Temp
    temp1.barking();
    temp1.speak();
    return 0;
}
