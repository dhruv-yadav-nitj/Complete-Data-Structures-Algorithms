// Write the frequency of each element in a sorted array
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
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int i = 0;
    while (i < n)
    {
        int count = 1;
        while ((arr[i] == arr[i + 1]) and (i + 1 < n))
        {
            count++;
            i++;
        }

        cout << arr[i] << " " << count << " " << endl;
        i++;
    }

    return 0;
}