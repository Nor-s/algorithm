#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <utility>
#include <map>

using namespace std;

vector<vector<int>> vv;
vector<int> visit;
int cnt = -1;
int answer = -1;

void dfs(int n, int now, int per_b)
{
    visit[now] = 1;
    cnt++;
    if (now == per_b)
    {
        answer = cnt;
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (visit[i] == 1)
            continue;
        if (vv[now][i] == 0)
            continue;
        dfs(n, i, per_b);
    }
    cnt--;
}

int main()
{
    int n;
    cin >> n;
    int pa, pb;
    cin >> pa >> pb;
    int m;
    cin >> m;
    vv = vector<vector<int>>(100, vector<int>(100, 0));
    for (int i = 0; i < m; i++)
    {
        int p, c;
        cin >> p >> c;
        vv[p][c] = 1;
        vv[c][p] = 1;
    }
    dfs(n, pa, pb);
    cout << answer << "\n";
}