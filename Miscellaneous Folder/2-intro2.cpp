#include <bits/stdc++.h>
#define l long long
#define vl vector<long long>
#define vi vector<int>
#define v2 vector<vector<int>>
using namespace std;

int main()
{
    int a = 10;
    int *ptr = &a;
    *ptr = 20;
    // important --^
    cout << a << endl;

    // int *ptr2;
    // instead of declaring such pointers do this , as the above method is wrong practice
    int *ptr2 = 0;
    ptr2 = &a;
    // a pointer can be also initialised like this as shown in line 17 & 18

    // copying a pointer
    int *qtr = ptr;
    cout << qtr << " " << ptr << endl;
    cout << qtr << " " << *qtr << endl;
    // it does qtr = ptr and both qtr and ptr are pointing to the same location

    int i = 1;
    int *ptrI = &i;
    cout << ++(*ptrI) << endl;

    return 0;
}