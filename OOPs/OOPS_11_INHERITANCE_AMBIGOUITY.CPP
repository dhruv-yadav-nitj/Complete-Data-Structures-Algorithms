#include <bits/stdc++.h>
using namespace std;

class A
{
public:
    void speak()
    {
        cout << "This is A." << endl;
    }
};

class B
{
public:
    void speak()
    {
        cout << "This is B." << endl;
    }
};

// inheritance ambiguoty:- we have a derived class which is inhereting two classes both of which have a member with the same name. Now we need to tell the code for which member we are talking about. This is done by Scope Resolution Operator (::)
class Derived : public A, public B
{
public:
};

int main(int argc, char const *argv[])
{
    Derived temp;

    // use of Scope Resolution
    temp.A ::speak();
    temp.B ::speak();
    return 0;
}