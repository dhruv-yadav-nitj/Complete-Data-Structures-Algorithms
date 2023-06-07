#include <bits/stdc++.h>
using namespace std;

class Hero
{
    // by default in private
    int age, height;

    int getAge()
    {
        return this->age;
    }
};

int main(int argc, char const *argv[])
{
    Hero temp1;
    cout << "All is Well" << endl; // this line gets executed means all the code gone well
    return 0;
}

// Encapsulation and Abstraction are almost related... Encapsulation is Data Hiding and Abstraction is Implementation Hiding.
// https://stackoverflow.com/questions/742341/difference-between-abstraction-and-encapsulation