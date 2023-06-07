#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std ;

int main(int argc, char const *argv[])
{
    int n ;
    cout << "Enter the limit: " ;
    cin >> n ;

    int sum = 0;
   for (int i = 0; i <= n; i++)
   {
       if (i % 2 == 0)
       {
           sum +=i ;
       }
       else
       {
           continue;
       }
   }
   cout << sum << endl ;
    

    return 0;
}