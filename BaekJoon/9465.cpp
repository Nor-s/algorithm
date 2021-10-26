#include <iostream>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <tuple>
#include <algorithm>
#include <vector>

using namespace std;
// 9 54
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
vector<int> b[2];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        b[0].resize(n + 1, 0);
        b[1].resize(n + 1, 0);
        for (int i = 0; i < 2; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cin >> b[i][j];
            }
        }
        int cached[100001][3];
        memset(cached, 0, sizeof cached);
        for (int i = 1; i <= n; i++)
        {
            cached[i][0] = max(cached[i - 1][1], cached[i - 1][2]) + b[0][i];
            cached[i][1] = max(cached[i - 1][0], cached[i - 1][2]) + b[1][i];
            cached[i][2] = max({cached[i - 1][2], cached[i - 1][1], cached[i - 1][0]});
        }
        cout << max({cached[n][0], cached[n][1], cached[n][2]}) << "\n";
    }
}