#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <tuple>

// 60
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    vector<vector<int>> v(T, vector<int>(3));
    int ans = 0;
    for (int i = 0; i < T; i++)
    {
        cin >> v[i][0] >> v[i][1] >> v[i][2];
        // first == 1 -> petya sure aboud solusion or not
        // second ==
        if (v[i][0] + v[i][1] + v[i][2] > 1)
        {
            ans++;
        }
    }
    cout << ans;
}