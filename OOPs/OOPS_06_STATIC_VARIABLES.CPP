#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/static-keyword-cpp/

void staticPrint()
{
    static int count(0);
    int temp(0);
    cout << "This is static: " << count++ << endl;
    cout << "This is not static: " << temp++ << endl;
}
int main(int argc, char const *argv[])
{
    int t(5);
    while (t--)
    {
        staticPrint();
    }

    // notice that the static variable is called only once and not every time it the function is called.

    return 0;
}
