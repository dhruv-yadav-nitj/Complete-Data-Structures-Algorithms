#include <bits/stdc++.h>
// if we use #include <iostream> then we need to include an header file for each STL like for seperate for array, sepearate for vectors,etc. but since we are using bits header file it would take care of all the header files needed for most of the programs
// #include <array>

using namespace std;

int main()
{
    array<int, 5> a = {1, 2, 3, 4, 5};
    int size = a.size();

    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n" ;
    cout << "Element at index 2 --> " << a.at(2) << endl;

    cout << "Is the array empty ? " << a.empty() << endl;
    // a.empty() is a bool function which returns either 0 or 1 ;
    cout << "First Element : " << a.front() << endl;
    cout << "Last Element : " << a.back() << endl;

    return 0;
}