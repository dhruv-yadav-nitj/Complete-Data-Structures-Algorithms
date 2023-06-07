// we have three types of constructors
// default, parametrised and Copy
// https://www.geeksforgeeks.org/constructors-c/
// this article has it all

// this article is about default constructors
#include <bits/stdc++.h>
using namespace std;

class construct
{
public:
    int a, b;

    // defualt constructor
    construct()
    {
        a = 10;
        b = 12;
    }
};

// showcasing explicit default constructor
// if we dont make any constructor explicitly, the complier will make a constructor implicitly

class construct2
{
private:
    int a, b;

public:
    construct2()
    {
        cin >> a >> b;
        cout << "a is: " << a << " "
             << "b is: " << b << endl;
    }

    // default constructors has no paramters
};

int main(int argc, char const *argv[])
{
    construct temp1;
    cout << temp1.a << " " << temp1.b << endl;

    construct2 temp2;

    return 0;
}
