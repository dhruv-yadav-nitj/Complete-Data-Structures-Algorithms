#include <bits/stdc++.h>
#define l long long
#define vl vector<long long>
#define vi vector<int>
#define v2 vector<vector<int>>
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
using namespace std;

/*
Tower of Hanoi is a mathematical puzzle where we have three rods (A, B, and C) and N disks. Initially, all the disks are stacked in decreasing value of diameter i.e., the smallest disk is placed on the top and they are on rod A. The objective of the puzzle is to move the entire stack to another rod (here considered C), obeying the following simple rules:

Only one disk can be moved at a time.
Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack i.e. a disk can only be moved if it is the uppermost disk on a stack.
No disk may be placed on top of a smaller disk.
*/

// Trick to Remember: source, desti, helper ; source, helper, desti ; helper, desti, source

int toh(int n, char source, char desti, char helper)
{
    if (n == 0)
    {
        return 0;
    }
    toh(n - 1, source, helper, desti);
    cout << "Move Disk " << n << " from " << source << " to " << desti << endl;

    toh(n - 1, helper, desti, source);

    // Total No. of Moves = pow(2, N)-1
    return pow(2, n) - 1;
}

// time complexity: O(pow(2, n))
// aux space: O(n)

int main()
{
    IOS;
    int n;
    cin >> n;
    cout << toh(n, 'A', 'C', 'B') << endl;

    return 0;
}