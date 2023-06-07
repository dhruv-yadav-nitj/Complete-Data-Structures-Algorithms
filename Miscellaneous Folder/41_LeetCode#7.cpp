
// reverse integer

#include <iostream>
#include <cstdio>
#include <math.h>
#include <cstring>
#include <string>

using namespace std ;

int main(int argc, char const *argv[])
{
    int x;
    cin >> x ;

    int ans = 0;
    while (x!=0)
    {
        if (ans > (INT_MAX/10) || ans < (INT_MIN/10))
        {
            return 0;
        }
        else
        {  
            ans = ans*10 + (x%10);
            x /= 10;
        }
    }
    return ans ;

}