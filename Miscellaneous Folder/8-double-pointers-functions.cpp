#include <bits/stdc++.h>
#define l long long
#define vl vector<long long>
#define vi vector<int>
#define v2 vector<vector<int>>
using namespace std;

void update(int **ptr)
{
    // saare cases ko ek ek kr ke chala kr dekho and diff smjho

    // case 1
    // ptr = ptr + 1 ;

    // case 2
    // *ptr = *ptr + 1;

    // case 3
    **ptr = **ptr +1 ;
}

int main()
{
    int var = 10;
    int *ptr = &var;
    int **ptr2 = &ptr;

    cout << "Before\n"
         << var << " " << ptr << " " << ptr2 << " " << *ptr << " " << *ptr2 << " " << **ptr2 << endl;

    update(ptr2);

    cout << "After\n"
         << var << " " << ptr << " " << ptr2 << " " << *ptr << " " << *ptr2 << " " << **ptr2 << endl;

    return 0;
}