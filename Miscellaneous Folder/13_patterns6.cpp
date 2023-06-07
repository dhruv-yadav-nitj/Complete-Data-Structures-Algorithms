#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std ;

int main(int argc, char const *argv[])
{
    int n ;
    cin >> n ;
    int count = 0 ;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            count = i ;
            cout << count << " " ;
        }
        cout << endl ;
    }
    

    return 0;
}