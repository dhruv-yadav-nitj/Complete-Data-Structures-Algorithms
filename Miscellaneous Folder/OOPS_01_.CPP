#include <bits/stdc++.h>
using namespace std;

class Hero
{
public:
    int val;

private:
    int health;

public:
    // setter for health
    // since we can't access health(a private entity) outside this class but we can access other public functions of this class and can use them as getter and setters for that private entity.

    // setter
    void setHealth(int h)
    {
        health = h;
    }

    // getter
    int getHealth()
    {
        return health;
    }

    // setter password protected
    void setPass(int h, string pass)
    {
        if (pass == "dhruv.nitj")
        {
            health = h;
        }
    }

    char alpha;
};

int main(int argc, char const *argv[])
{
    Hero zero;
    zero.val = 0;
    cout << "Line 1: " << sizeof(zero) << endl;
    cout << "Line 2: " << zero.val << endl;

    // lets try to access health which is a private entity
    // zero.health = 0;
    // line 21 ko uncomment krke dekho error aa rha hoga use pdho

    // now to access the private entities inside a class we need to write getters and setters

    zero.setHealth(10);
    cout << "Line 3: " << zero.getHealth() << endl;

    // suppose we are building a password protected entity then setter can be used as

    zero.setPass(20, "dhruv.nitj");
    cout << "Line 4: " << zero.getHealth() << endl;

    // now lets try with wrong password
    zero.setPass(30, "dhruv");
    cout << "Line 5: " << zero.getHealth() << endl;
    // u will notice that the level does not gets changed

    // static allocation
    Hero one;

    // dynamic allocation
    Hero *two = new Hero;
    // (*Two)/level can be written as Two-> level

    two->val = 2;
    cout << "Line 6: " << two->val << endl;

    two->setHealth(100);
    cout << "Line 7: " << two->getHealth() << endl;

    return 0;
}
