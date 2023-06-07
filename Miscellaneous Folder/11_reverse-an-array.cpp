
// code-studio

// alrady did the same ques before using arrays, now we would do the same using vectors

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v1;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v1.push_back(a);
    }
    int s = 0, e = n - 1;
    while (s < e)
    {
        swap(v1[s], v1[e]);
        s++, e--;
    }
    for (int i = 0; i < n; i++)
    {
        cout << v1[i] << " ";
    }
    cout << endl;

    return 0;
}