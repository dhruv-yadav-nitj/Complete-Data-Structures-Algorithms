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
    // other ways to create a multidimensional array

    cout << "Method 1 " << endl;
    // Method 1: Using Double Pointer
    // m is the number of rows and n is the number of columns
    int m(3), n(2);
    int **arr;
    arr = new int *[m];
    for (int i = 0; i < m; i++)
    {
        arr[i] = new int[n];
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = 10;
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Method 2" << endl;
    // method 2: using array of pointers
    int row(3), col(2);
    int *arrNew[m];
    for (int i = 0; i < row; i++)
    {
        arrNew[i] = new int[col];
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            arrNew[i][j] = 20;
            cout << arrNew[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Method 3" << endl;
    // method 3: using vector
    // row = 3 and col = 2
    vector<int> arrVec[row];
    // here am creating an array of vectors, a row is a vector but am creating m different row which makes it a 2d array
    // notice that in this case two different rows can have different sizes, since the size of a vector is not defined
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            arrVec[i].push_back(30);
        }
    }

    // printing the 2d vector array
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arrVec[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Method 4" << endl;
    // we can use vector of vectors
    // here both no. of rows and col can be dynamic
    vector<vector<int>> newArr;
    // using row(3) and col(2);
    for (int i = 0; i < m; i++)
    {
        vector<int> temp;
        for (int j = 0; j < col; j++)
        {
            temp.push_back(40);
        }
        newArr.push_back(temp);
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << newArr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}