#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std ;

int main(int argc, char const *argv[])
{
    cout << "Enter anything: " ;
    char ch ;
    cin >> ch ;

    if (ch >= 'a'&& ch <= 'z')
    {
        cout << "Lower Case" << endl ;
    }
    else if (ch >= 'A' && ch <= 'Z')
    {
        cout << "Upper Case" << endl ;
    }
    else if (ch >= '0' && ch <= '9')
    {
        cout << "Numeric Value" << endl ;
    }
    

    return 0;
}