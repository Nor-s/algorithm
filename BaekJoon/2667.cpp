#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int visited[26][26];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int n;

char board[26][26];

int dfs(int i, int j)
{
    int count = 1;
    visited[i][j]++;
    board[i][j] = '4';
    for (int k = 0; k < 4; k++)
    {
        int ii = i + dy[k];
        int jj = j + dx[k];
        if (ii < 0 || jj < 0 || ii >= n || jj >= n)
        {
            continue;
        }
        else if (visited[ii][jj] == 0 && board[ii][jj] == '1')
        {
            count += dfs(ii, jj);
        }
    }
    return count;
}
void dfsall()
{
    vector<int> c;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (visited[i][j] == 0 && board[i][j] == '1')
            {
                c.push_back(dfs(i, j));
            }
        }
    }
    sort(c.begin(), c.end());
    cout << c.size() << "\n";
    for (int i = 0; i < c.size(); i++)
    {
        cout << c[i] << "\n";
    }
}
int main()
{
    cin >> n;
    memset(visited, 0, sizeof visited);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }
    dfsall();
}