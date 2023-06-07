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

void mergeInSortedOrder(int arr[], int ll, int m, int h)
{
    int k = ll;
    int i = ll;
    int j = m + 1;
    int temp[h + 1];
    while (i <= m and j <= h)
    {
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    while (i <= m)
        temp[k++] = arr[i++];
    while (j <= h)
        temp[k++] = arr[j++];
    for (int i = ll; i <= h; i++)
    {
        arr[i] = temp[i];
    }
}

void mergeSort(int arr[], int low, int high)
{

    if (low < high)
    {
        int mid = low + (high - low) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        mergeInSortedOrder(arr, low, mid, high);
    }
    else
    {
        return;
    }
}

int main()
{
    IOS;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        mergeSort(arr, 0, n - 1);
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
    }

    return 0;
}