
// https://leetcode.com/problems/rotate-image/

// must study method 2 given on the below link
// https://www.geeksforgeeks.org/rotate-a-matrix-by-90-degree-in-clockwise-direction-without-using-any-extra-space/?ref=gcse

#include <bits/stdc++.h>
#define l long long
using namespace std;

void reverseMatrix (int matrix[][3], int n, int m)
{
    for (int j = 0; j < n; j++)
    {
        for (int i = n-1; i >= 0; i--)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl ;
    }
    
}

int main()
{
    int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    reverseMatrix (matrix, 3, 3) ;
    return 0;
}