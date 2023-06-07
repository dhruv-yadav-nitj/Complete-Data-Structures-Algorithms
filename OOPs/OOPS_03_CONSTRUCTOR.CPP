#include <bits/stdc++.h>
using namespace std;

class construct
{
    // lets see what parametrised constuctor is
    // as the name suggests it would be having parameters
    /* It is possible to pass arguments to constructors. Typically, these arguments help initialize an object when it is created. To create a parameterized constructor, simply add parameters to it the way you would to any other function. When you define the constructor’s body, use the parameters to initialize the object.  */

private:
    int a, b;

public:
    construct(int x, int y)
    {
        a = x, b = y;
    }

    int getA()
    {
        return a;
    }
    int getB() { return b; }
};

int main(int argc, char const *argv[])
{
    construct temp(10, 20);
    cout << temp.getA() << " " << temp.getB() << endl;
    return 0;
}
