#include <iostream>
#include <vector>

using namespace std;

vector<vector<bool>> visited;
vector<vector<int>> board;
vector<pair<int, int>> v;
int w, h;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
void dfs(int y, int x)
{
    visited[y][x] = true;
    for (int i = 0; i < 4; i++)
    {
        int yy = y + dy[i];
        int xx = x + dx[i];
        if (yy < 0 || xx < 0 || yy >= h || xx >= w || visited[yy][xx] || board[yy][xx] == 0)
        {
            continue;
        }
        dfs(yy, xx);
    }
}

int dfsAll()
{
    int answer = 0;
    for (int i = 0; i < v.size(); i++)
    {
        auto [y, x] = v[i];
        if (!visited[y][x])
        {
            answer++;
            dfs(y, x);
        }
    }
    return answer;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int k;
        cin >> w >> h >> k;
        visited.clear();
        visited.resize(h, vector<bool>(w, false));
        board.clear();
        board.resize(h, vector<int>(w, 0));
        v.clear();
        for (int i = 0; i < k; i++)
        {
            int y, x;
            cin >> x >> y;
            v.push_back({y, x});
            board[y][x] = 1;
        }
        cout << dfsAll() << "\n";
    }
}