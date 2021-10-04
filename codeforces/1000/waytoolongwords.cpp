#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;
// 5 25
// 5 35

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    while (N--)
    {
        string s;
        cin >> s;
        //  strictly more than 10
        if (s.size() > 10)
        {
            cout << s[0] << s.size() - 2 << s.back() << "\n";
        }
        else
        {
            cout << s << "\n";
        }
    }
}