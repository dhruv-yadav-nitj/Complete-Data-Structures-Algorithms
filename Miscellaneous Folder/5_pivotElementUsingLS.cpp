#include <bits/stdc++.h>
using namespace std ;

int main()
{
    int array[] = {7, 9 ,1, 2, 3} ;
    int ans = INT_MAX ;
    for (int i = 0; i < sizeof(array)/sizeof(int); i++)
    {
        if (array[i]<ans)
        {
            ans = array[i] ;
        }
        
    }
    
    cout << "Pivot Element: " << ans << endl ;
    return 0;
}

// slow due to large TC i.e., O(n) 