
// Problem Statement : Print all the subsequences of an array

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

// time complexity : O(pow(2, n) * n)
// since a single recursion call if giving birth to more recursion calls plus we are using a for loop for the printing of subsequences

// space complexity : O(n)
// since at an instant of time there is no more than 3 number of recursion calls waiting for in the stack space

void printPermut(int arr[], int n, int i, vector<int> &sub)
{
    // writing base conditions is the most important part of recursion
    if (i == n)
    {
        if (sub.size() == 0)
        {
            cout << "{ }" << endl;
        }
        else
        {
            for (int i = 0; i < sub.size(); i++)
            {
                cout << sub[i] << " ";
            }
            cout << endl;
        }

        return;
    }

    // take
    sub.push_back(arr[i]);
    printPermut(arr, n, i + 1, sub);

    // not take
    sub.pop_back();
    printPermut(arr, n, i + 1, sub);
}

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
    vector<int> sub;
    cout << endl;
    printPermut(arr, n, 0, sub);

    return 0;
}