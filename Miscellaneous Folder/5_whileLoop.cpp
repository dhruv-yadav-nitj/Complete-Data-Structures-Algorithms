#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std ;

int main(int argc, char const *argv[])
{
    int rupee = 100 , count = 0 ;
    while (rupee != 0)
    {
        cout << "Eat more bananas." << endl ;
        count ++ ;
        rupee -= 10 ;
    }
    cout << "Total bananas ate: " << count << endl ;

    return 0;
}