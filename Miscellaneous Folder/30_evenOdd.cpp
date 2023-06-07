#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std ;

int main(int argc, char const *argv[])
{
    int n ;
    cout << "Enter some number: " ;
    cin >> n ;

    if (n&1 == 0)
    {
        cout << "even" << endl ;
    }
    else
    {
        cout << "odd" << endl ;
    }
    

    return 0;
}