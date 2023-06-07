#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std ;

int main(int argc, char const *argv[])
{
    int n ;
    cin >> n ;

    char count = 'A' ;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << count << " " ;
        }
        count ++ ;
        cout << endl ;
    }
    

    return 0;
}