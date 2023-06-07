#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std ;

int main(int argc, char const *argv[])
{
    int n ;
    cin >> n ;

    for (int i = 1; i <= n; i++)
    {
        int count = i;
        for (int j = 1; j <= i; j++)
        {            
            cout << count << " " ;
            count -- ;
        }
        cout << endl ;
    }
    

    return 0;
}