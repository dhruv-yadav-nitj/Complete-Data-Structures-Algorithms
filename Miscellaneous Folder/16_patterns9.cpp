#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std ;

int main(int argc, char const *argv[])
{
    int n ;
    cin >> n ;
    char ch = 'A' ;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << ch << " ";
            ch ++ ;
        }
        ch = ch - 2 ;
        cout << endl ;
    }
    

    return 0;
}