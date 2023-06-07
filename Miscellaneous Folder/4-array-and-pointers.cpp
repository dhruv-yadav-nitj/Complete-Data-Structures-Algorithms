#include <bits/stdc++.h>
#define l long long
#define vl vector<long long>
#define vi vector<int>
#define v2 vector<vector<int>>
using namespace std;

int main()
{
    int arr[10] = {2, 4, 6};
    cout << "Address of first element of arr is : " << arr << endl;
    cout << "Address of first element of arr is : " << &arr[0] << endl;
    cout << "Address of second element of arr is : " << (arr + 1) << endl ;

    int *ptr = &arr[0];
    cout << "1st Element: " << *(arr) << endl ;
    cout << "3rd Element: " << *(arr + 3) << endl ;
    cout << "3rd Element: " << *(ptr + 2) << endl;
    cout << "1st Element + 3 is : " << *ptr + 3 << endl;

    /*
    Important Note:
    int *ptr = arr[0] ;
    then
    arr[i] = *(ptr + i) is same as i[arr] = *(i + arr)
         */

    cout << "3rd Element: " << 2 [arr] << endl;
    cout << "3rd Element: " << *(2 + ptr) << endl;

    cout << sizeof(arr) << ' ' << sizeof(ptr) << ' ' << sizeof(*ptr) << endl;

    // both would be different
    cout << &ptr << " " << &arr[0] << endl ;

    int arr2[] = {1, 2, 3} ;
    int *samplePtr = &arr2[0] ;

    // error
    // arr2 = arr2 + 1 ;
    // i.e., we cannot change the address of some element of an array, but we can do the same with pointers

    cout << int(samplePtr) << endl ;
    
    // now there would be 1* (sizeof(datatype of samplePtr)) added to samplePtr ;
    samplePtr += 1 ;
    cout << int(samplePtr) << endl ;

    return 0;
}