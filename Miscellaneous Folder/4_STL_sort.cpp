#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[5];
    for (int i = 0; i < 5; i++)
    {
        cin >> arr[i];
    }

    // sort in increasing order
    sort(arr, arr + 5);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // sort in decreasing order
    sort(arr, arr + 5, greater<int>());
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}