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

int main()
{
    IOS;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        string ans = "";
        vector<int> charNumbers;
        for (int i = s.length() - 1; i >= 0; i--)
        {
            if (s[i] == '0')
            {
                string temp = "";
                temp += s[i - 2];
                temp += s[i - 1];
                int tempo = stoi(temp);
                charNumbers.push_back(tempo);
                i = i - 2;
            }
            else
            {
                string temp = "";
                temp += s[i];
                int tempo = stoi(temp);
                charNumbers.push_back(tempo);
            }
        }
        reverse(charNumbers.begin(), charNumbers.end()) ;
        for (int i = 0; i < charNumbers.size(); i++)
        {
            // cout << charNumbers[i] << " "  ;
            ans += char(96+charNumbers[i]) ;
        }
        // cout << endl ;
        cout << ans << endl ;
    }

    return 0;
}