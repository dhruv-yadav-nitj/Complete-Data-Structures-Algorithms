#include <bits/stdc++.h>
#define l long long
#define vl vector<long long>
#define vi vector<int>
#define v2 vector<vector<int>>
using namespace std;

void printPat(int n)
{
    for (int i = n; i >= 1; i--)
    {
        int count = 1, temp = n;
        for (int j = n * i; j >= -n; j--)
        {
            if (count <= i and temp >= 1)
            {
                cout << temp << " ";
                count++;
            }
            else
            {
                count = 1;
                temp--;
            }
        }
        cout << "\n";
    }
}

int main()
{
    int n;
    cin >> n;
    printPat(n);

    return 0;
}