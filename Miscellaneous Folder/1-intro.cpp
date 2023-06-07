#include <bits/stdc++.h>
#define l long long
#define vl vector<long long>
#define vi vector<int>
#define v2 vector<vector<int>>
using namespace std;

int main()
{
    int num = 10;
    // * operator is used to declare a pointer and & operator stands for the address of the variable
    // if you dont want to intialise a pointer but want to declare it then you can use zero at that moment (this is known as null pointer)
    int *ptr = &num;
    cout << ptr << endl;

    // dereferencing
    cout << *ptr << endl;

    // intitialising a null pointer
    int *ptr1 = NULL;
    // It should be noted that NULL pointer is different from an uninitialized and dangling pointer. In a specific program context, all uninitialized or dangling or NULL pointers are invalid but NULL is a specific invalid pointer which is mentioned in C standard and has specific purposes. What we mean is that uninitialized and dangling pointers are invalid but they can point to some memory address that may be accessible through the memory access is unintended.

    // Dangling pointers and wild pointers in computer programming are pointers that do not point to a valid object of the appropriate type. These are special cases of memory safety violations.

    // the size of a pointer is always constant i.e., 8 or 4 bits
    cout << sizeof(ptr) << endl;
    double oral6 = pow(2, 10);
    double *pptr = &oral6;
    cout << pptr << " " << *pptr << " " << sizeof(pptr) << endl;

    return 0;
}