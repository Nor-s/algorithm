#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
// 12:30
// 5:10
using namespace std;
//1~1000
int n, m;
vector<string> nm;
// square '1'
// cached[y][x] = (y, x) 에서 시작하는 가장긴 가로길이
int cached[1000][1000];
int answer = 0;

int len(int y, int x)
{
    if(cached[y][x] != -1) {
        return cached[y][x];
    }
    else if(x == m) {
        return 0;
    }
    else if (nm[y][x] == '0')
    {
        return cached[y][x] = 0;
    }
    return cached[y][x] = len(y, x + 1) + 1;
}
// dp(y, x, topLen) = topLen
void dp(int y, int x, int width, int depth)
{
    answer = max(answer, (depth+1)*(depth+1));
    if(y == n) {
        return;
    }
    for (int i = x; i < x + width;)
    {
        int l = len(y, i);
        if (l == 0)
        {
            i++;
        }
        else
        {
            if(min(l, x + width - i)> depth + 1) {
                dp(y+1, i, min(l, x + width - i), depth+1);
            }
            i += l;
        }
    }
    if(depth == -1) {
        return dp(y+1, 0, m, -1);
    }
    else {
        return;
    }
}

void solve()
{
    dp(0, 0, m, -1);
    cout << answer;
}
/*

4 4
0100
0111
1110
0010

*/
int main()
{
    cin >> n >> m;
    nm.resize(n, string(m, '0'));
    memset(cached, -1, sizeof cached);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> nm[i][j];
        }
    }
    solve();
}