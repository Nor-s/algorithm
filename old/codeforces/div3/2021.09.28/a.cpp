#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    while (T--)
    {
        string s;

        cin >> s;
        int alpha[3] = {0, 0, 0};

        for (int i = 0; i < s.length(); i++)
        {
            alpha[s[i] - 'A']++;
        }
        if (alpha[0] + alpha[2] == alpha[1])
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}