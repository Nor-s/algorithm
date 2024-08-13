#include <iostream>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

string str[3];
bool visited[201][201];

struct State
{
    int a;
    int b;
};

bool bfs()
{
    queue<State> q;
    q.push({0, 0});
    memset(visited, 0, sizeof(visited));
    visited[0][0] = true;

    while (!q.empty())
    {
        auto [aIdx, bIdx] = q.front();
        q.pop();

        int findIdx = aIdx + bIdx;
        if (findIdx == str[2].size())
        {
            return true;
        }
        if (aIdx < str[0].size() && str[2][findIdx] == str[0][aIdx] && visited[aIdx + 1][bIdx] == 0)
        {
            visited[aIdx + 1][bIdx] = 1;
            q.push({aIdx + 1, bIdx});
        }
        if (bIdx < str[1].size() && str[2][findIdx] == str[1][bIdx] && visited[aIdx][bIdx + 1] == 0)
        {
            visited[aIdx][bIdx + 1] = 1;
            q.push({aIdx, bIdx + 1});
        }
    }
    return false;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n;
    cin >> n;

    for (int t = 0; t < n; t++)
    {
        cin >> str[0] >> str[1] >> str[2];
        int size = str[2].size();

        cout << "Data set " << t + 1 << ": ";
        if (bfs())
            cout << "yes\n";
        else
            cout << "no\n";
    }
}