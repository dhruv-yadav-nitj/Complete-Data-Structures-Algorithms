
// vector is a dynamic array. which means it can extend its capacity to double the prev capacity, if the prev size becomes less
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v;
    // initialising a vector
    vector <int> vector1(5,1) ;
    cout << "Vector1 --> \n" ;
    for (auto x: vector1)
    {
        cout << x << " " ;
    }cout << endl ;

    vector <int> vector2 (vector1) ;
    // this means that initialise an vector named vector2 with all the elements of vector1 present in it
    cout << "Vector2 --> \n"  ;
    for (auto x: vector2)
    {
        cout << x << " " ;
    }cout << endl ;
    
    
    // 5 denotes the size of vector and 1 denotes that we want to initialise all the elements with 1 only 
    cout << "Capacity --> " << v.capacity() << endl;
    // capcaity returns the total capacity of the vector whereas size returns the current size of vector.
    // capacity means the total number of memory assigned to the vector whereas size returns the total number of elements in the vector/array

    v.push_back(1);
    cout << "Capacity --> " << v.capacity() << endl;

    v.push_back(2);
    cout << "Capacity --> " << v.capacity() << endl;

    v.push_back(3) ;
    cout << "Capacity --> " << v.capacity() << endl;
    // notice that the capacity gets double 
    
    cout << "Before Pop: \n";
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;

    v.pop_back();
    cout << "After Pop: \n";
    for (auto i : v)
    {
        cout << i << " ";
    }
    // to empty the array we can use 
    v.clear() ;
    cout << v.size() << endl; 
    return 0;
}