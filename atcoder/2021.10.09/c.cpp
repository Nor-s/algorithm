
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<char>> A;
int N, M;

void solve()
{
    vector<pair<int, int>> rank(A.size());
    for (int i = 0; i < rank.size(); i++)
    {
        rank[i] = {0, i};
    }
    for (int m = 0; m < M; m++)
    {
        for (int a = 0, b = 1; a < rank.size(); a += 2, b += 2)
        {
            int aa = rank[a].second;
            int bb = rank[b].second;
            // C0 = scissor. < G1= rock , < P2 = paper
            if ((A[aa][m] + 1) % 3 == A[bb][m])
            {
                rank[b].first++;
            }
            else if (A[aa][m] == A[bb][m])
            {
            }
            else
            {
                rank[a].first++;
            }
        }
        sort(rank.begin(), rank.end(), [](pair<int, int> &aaa, pair<int, int> &bbb)
             {
                 if (aaa.first == bbb.first)
                     return aaa.second < bbb.second; // 작은것 위로
                 else
                     return aaa.first > bbb.first; // 많이 이긴놈 위로
             });
    }
    for (int i = 0; i < rank.size(); i++)
    {
        cout << rank[i].second + 1 << "\n";
    }
}

int main()
{
    cin >> N >> M;
    A.clear();
    A.resize(2 * N, vector<char>(M));
    for (int i = 0; i < 2 * N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> A[i][j];
            if (A[i][j] == 'C')
            {
                A[i][j] = 0;
            }
            if (A[i][j] == 'P')
            {
                A[i][j] = 2;
            }
            if (A[i][j] == 'G')
            {
                A[i][j] = 1;
            }
        }
    }
    solve();
}