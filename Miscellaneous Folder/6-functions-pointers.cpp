#include <bits/stdc++.h>
#define l long long
#define vl vector<long long>
#define vi vector<int>
#define v2 vector<vector<int>>
#define endl "\n"
using namespace std;

// known as Pass by Value

void print(int *ptr)
{
    cout << *ptr << endl;
}

void update(int *ptr)
{
    // dont write *ptr++ for *ptr = *ptr + 1 as its not gonna work
    *ptr = *ptr + 1;
}

int main()
{
    int temp = 5;
    int *ptr = &temp;
    print(ptr);
    update(ptr);
    cout << "main: " << temp << endl;

    return 0;
}