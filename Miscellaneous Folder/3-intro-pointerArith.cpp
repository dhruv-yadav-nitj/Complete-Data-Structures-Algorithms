#include <bits/stdc++.h>
#define l long long
#define vl vector<long long>
#define vi vector<int>
#define v2 vector<vector<int>>
using namespace std;

int main()
{
    int i = 5;
    int *ptr = &i;
    cout << int(ptr) << endl;
    cout << int(++ptr) << endl;
    // notice the output , we would get a difference of 4 in both the output , which is because we are changing the value stored at ptr and not at *ptr, value stored at ptr is some address and as we know that one int = 4 bits , so if ptr = 100 the ptr +1 would be 104

    // important property

    int var = 6 ;
    int *ptr1 = &var ;
    int *ptr2 = ptr1 ; // notice that we have not used & operator with ptr1
    cout << ++(*ptr2) << endl;

    return 0;
}