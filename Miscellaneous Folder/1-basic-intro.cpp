#include <bits/stdc++.h>
#define l long long
#define vl vector<long long>
#define vi vector<int>
#define vp vector<vector<int>>
using namespace std;

// declaring as a global variable
int count = 0;

void print()
{
    // to access global variables, we use :: before variable name
    ::count++;
    if (::count > 5)
    {
        return;
    }
    cout << ::count << " ";
    print();
}

int main()
{
    print();

    return 0;
}