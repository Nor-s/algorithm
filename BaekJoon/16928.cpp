#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <tuple>
#include <iterator>
#include <map>
#include <set>
#include <cmath>
#include <queue>

using namespace std;

queue<tuple<int, int>> q;
map<int, int> ladder;
int yhi;
int xhi;

bool check[100];
int bfs()
{
    q.push({1, 0});
    while (!q.empty())
    {
        auto [x, day] = q.front();
        q.pop();
        if (x == 100)
        {
            return day;
        }
        for (int i = 1; i <= 6; i++)
        {
            int new_x = ladder[x + i];
            if (new_x < 101 && !check[new_x])
            {
                check[new_x] = true;
                q.push({new_x, day + 1});
            }
        }
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i < 111; i++)
    {
        ladder[i] = i;
    }
    for (int i = 0; i < n + m; i++)
    {
        int a, b;
        cin >> a >> b;
        ladder[a] = b;
    }
    cout << bfs();
}