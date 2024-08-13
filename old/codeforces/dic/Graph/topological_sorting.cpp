#include <iostream>
#include <vector>

using namespace std;

vector<vector<bool>> adjlist;
vector<bool> visited;
vector<int> s;

bool dfs(const int &x)
{
    visited[x] = true;
    for (int i = 0; i < adjlist[x].size(); i++)
    {
        if (adjlist[x][i] == false)
            continue;
        if (visited[i])
        {
            auto iter = find(s.begin(), s.end(), i);
            if (iter == s.end())
                return false;
        }
        else
        {
            if (!dfs(i))
                return false;
        }
    }
    s.push_back(x);
    return true;
}
void dfsAll(int N)
{
    visited = vector<bool>(N, false);
    for (int i = 0; i < N; i++)
    {
        if (!visited[i])
        {
            if (!dfs(i))
            {
                cout << 0; // false.
                return;
            }
        }
    }
    for (int i = N - 1; i >= 0; i--)
    {
        cout << s[i] + 1 << "\n"; // 스택 위에서부터 출력
    }
}