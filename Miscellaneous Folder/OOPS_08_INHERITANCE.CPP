#include <bits/stdc++.h>
using namespace std;

class Human
{
public:
    int age, weight;
    int height;

public:
    void setAge(int age)
    {
        this->age = age;
    }

    int getAge()
    {
        return age;
    }

private:
    int sex, diabetes;
    // private members cant be inherited to the child class. Even it is the only difference between Protected Class and Private Class, that Protected Members can be inherited to the child class but Private Members cant be.
protected:
    string highBloodPressure = "Hello, I am Protected Member of the Base Class.";
};

// creating a subclass
class Male : public Human
{
public:
    string color, religion, caste;
    void sleep()
    {
        cout << "Male is Sleeping." << endl;
    }
};

class Derived : public Human
{
public:
    // we can access the protected members of the base class in derived class usign getter and setters.
    void fun()
    {
        cout << highBloodPressure << endl;
    }
};

main(int argc, char const *argv[])
{
    Male m1;
    m1.setAge(10);
    cout << m1.getAge() << endl;

    m1.sleep();

    Derived temp1;
    temp1.fun();

    return 0;
}

// when inherited as public mode, the public members of super class come in sub class get inherited but private class come in private mode. when inherited as private mode, all the members come but in private mode