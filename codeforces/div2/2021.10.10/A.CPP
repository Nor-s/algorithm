#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#define cout1(a) cout << a
#define cout2(a, b) cout << a << b
#define cout3(a, b, c) cout << a << b << c
#define cout4(a, b, c, d) cout << a << b << c << d
#define cout5(a, b, c, d, e) cout << a << b << c << d << e

using namespace std;
int n;
// move  (x1,y1) to cell (x2,y2) if |x1−x2|≤1 and |y1−y2|≤1.
int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[] = {1, 0, -1, 0, 1, -1, 1, -1};
// trap -> die , end
//  (2, n) - game win

// 0 -> can / 1 - > trap
vector<char> board[2];

int dijkstra(int y, int x)
{
    vector<int> dist[2];
    dist[0].resize(n, 1e9);
    dist[1].resize(n, 1e9);
    dist[y][x] = 0;
    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push(make_pair(0, make_pair(y, x)));

    while (!pq.empty())
    {
        int cost = -pq.top().first;
        pair<int, int> here = pq.top().second;
        pq.pop();

        if (dist[here.first][here.second] < cost)
            continue;

        for (int i = 0; i < 8; i++)
        {
            int yy = here.first + dy[i];
            int xx = here.second + dx[i];
            if (yy < 0 || yy >= 2 || xx < 0 || xx >= n || board[yy][xx] == '1')
            {
                continue;
            }
            int nextDist = cost + 1;
            if (dist[yy][xx] > nextDist)
            {
                dist[yy][xx] = nextDist;
                pq.push(make_pair(-nextDist, make_pair(yy, xx)));
            }
        }
    }
    return dist[1][n - 1];
}

string solve()
{
    if (dijkstra(0, 0) <= 1e8)
    {
        return "YES";
    }
    else
    {
        return "NO";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    while (T--)
    {
        cin >> n;
        board[0].resize(n);
        board[1].resize(n);
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> board[i][j];
            }
        }
        cout2(solve(), '\n');
    }
}