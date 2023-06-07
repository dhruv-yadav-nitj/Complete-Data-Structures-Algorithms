// #include <bits/stdc++.h>
// #define l long long
// using namespace std;

// int main()
// {
//     int n, m;
//     cin >> n >> m;
//     int arr[100][100];
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             cin >> arr[i][j];
//         }
//     }
//     for (int j = 0; j < m; j++)
//     {
//         if (j % 2 == 0)
//         {
//             for (int i = 0; i < n; i++)
//             {
//                 cout << arr[i][j] << " ";
//             }
//         }
//         else
//         {
//             for (int i = n - 1; i >= 0; i--)
//             {
//                 cout << arr[i][j] << ' ';
//             }
//         }
//     }

//     return 0;
// }


// https://www.codingninjas.com/codestudio/problems/print-like-a-wave_893268

vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols)
{
    vector<int> ans;
    for (int j = 0; j < mCols; j++)
    {
        if (j % 2 == 0)
        {
            for (int i = 0; i < nRows; i++)
            {
                ans.push_back(arr[i][j]);
            }
        }
        else
        {
            for (int i = nRows - 1; i >= 0; i--)
            {
                ans.push_back(arr[i][j]);
            }
        }
    }
    return ans;
}