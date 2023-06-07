/* A copy constructor is a member function that initializes an object using another object of the same class.  */
#include <bits/stdc++.h>
using namespace std;

// Copy Constructors

class student
{
    int id; // by default it would be private

public:
    void whatToDo(int x)
    {
        id = x;
    }

    student(){}; // default constructor with empty body

    student(student &temp)
    {
        id = temp.id;
    }

    void getCheck()
    {
        cout << "ID: " << id << endl;
    }
};

int main(int argc, char const *argv[])
{
    // whenever we define a class with one or more non-default constructors(with parameters) for a class, a default constructor (without parameter) should be explicitly declared as compiler would not provide the default constructor in this case.

    // Copy constructor takes a reference to an object of the same class as an argument.

    student temp2;
    temp2.whatToDo(10);
    temp2.getCheck();

    student temp3(temp2);
    temp2.getCheck();

    return 0;
}
