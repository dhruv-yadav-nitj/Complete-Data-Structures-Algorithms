
// basic to sb jaante hain.
// assume you have a infinte loop and you have to use swtich statement inside the loop and exiting the 

#include <iostream>
#include <cstdio>
#include <math.h>
#include <cstring>
#include <string>

using namespace std ;

int main(int argc, char const *argv[])
{
    int num;
    cin >> num ;

    while (1)
    {
        switch (num)
        {
        case 1:
            cout << "one" << endl;
            exit (0);
        
        default:
            cout << "error 404" << endl;
            break;
        }
    }
    return 0;
}
// now once enter the value of 1 and once 2 and see the working