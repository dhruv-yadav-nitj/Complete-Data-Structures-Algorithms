#include <bits/stdc++.h>
using namespace std;

class Animal
{
public:
    void speak()
    {
        cout << "Speaking" << endl;
    }
};

class Dog : public Animal
{
public:
};

class GermanShepherd : public Dog
{
public:
};

int main(int argc, char const *argv[])
{
    GermanShepherd g1;
    g1.speak();
    return 0;
}
