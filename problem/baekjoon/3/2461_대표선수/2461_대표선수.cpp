// s:
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <cstring>
#include <string>
#include <functional>
#include <map>
#include <set>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    std::vector<std::vector<int>> board(N, std::vector<int>(M, 0));
    std::map<int, pair<int, int>> mp;
    std::set<int> mp_up;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];
        }
        sort(board[i].begin(), board[i].end());
        mp[board[i][0]] = {i, 0};
        mp_up.insert(-board[i][0]);
    }
    int answer = INT32_MAX;

    while (true)
    {
        answer = min(answer, -mp.begin()->first - *mp_up.begin());
        auto [idx, idx2] = mp.begin()->second;
        mp_up.erase(mp_up.find(-mp.begin()->first));
        mp.erase(mp.begin());
        idx2++;
        if (board[idx].size() == idx2)
        {
            break;
        }
        mp[board[idx][idx2]] = {idx, idx2};
        mp_up.insert(-board[idx][idx2]);
    }
    cout << answer;
}