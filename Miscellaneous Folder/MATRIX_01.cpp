#include <bits/stdc++.h>
#define l long long
#define vl vector<long long>
#define vi vector<int>
#define v2 vector<vector<int>>
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
using namespace std;

int main()
{
    IOS;
    // multidimensional array
    int arr[3][2] = {{11, 12}, {21, 22}, {31, 32}};
    // assume a 2d array as a matrix

    // example of a 3d array
    int arr3[][2][2] = {{{1, 2}, {3, 4}}, {{5, 6}, {7, 8}}};

    /*
    Notes:
    1. Elements are stored in contiguous and row-majored order (just like matrix in maths)
    2. Internal curly braces are optional.
    3. The first dimension can be omitted when we initialise or use a multidimensional in a function
    */

    int newArr[2][3] = {11, 12, 13, 21, 22, 23};
    // this newArr would have 2 rows and 3 columns
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << newArr[i][j] << " ";
        }
        cout << endl;
    }

    // variable sized multidimensional array
    int n, m;
    cin >> n >> m;
    // n is the number of rows and m is the number of columns
    int newArray[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> newArray[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << newArray[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}