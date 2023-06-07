
// https://www.geeksforgeeks.org/searching-algorithms-for-a-2d-arrays-matrix/?ref=gcse
#include <bits/stdc++.h>
#define l long long
using namespace std;

vector <int> linearSearch (vector <vector<int>> arr, int target)
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0 ; j < arr[0].size(); j++)
        {
            if (target == arr[i][j])
            {
                return {i, j} ;
            }
            
        }
    }
    return {-1, -1} ;
}

int main()
{
    // creating a 2D array based vector
    vector <vector<int>> arr = {{3, 12, 9}, {5, 2, 89}, {90, 45, 22}} ;
    int target = 89;
    vector<int> ans = linearSearch(arr, target);
    cout << "Element found at index: [" << ans[0] << " " << ans[1] << "]";

    return 0;
}