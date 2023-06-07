#include <iostream>
using namespace std ;

int main()
{
    int n;
    cin >> n ;
    int row = 0;
    while (row < n)
    {
        int col = 1;
        while (col <= n*2)
        {
            // left part
            if (col <= n)
            {
                if (row+col > n)
                {
                    cout << "* " ;
                }
                else
                {
                    cout << col << " " ;
                }
            }
            // right part
            else
            {
                int count = n*2 - col + 1;
                if (col-row>n)
                {
                    cout << count << " " ;
                }
                else
                {
                    cout << "* " ;
                }
            }
            col++ ;            
        }
        cout << "\n" ;
        row++ ;
    }
    return 0;
}