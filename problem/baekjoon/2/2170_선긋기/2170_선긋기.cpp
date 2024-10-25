
// s:
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <cstring>
#include <string>
#include <functional>

using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int N;
    cin >> N;
    vector<pair<int, int>> board;
    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        board.emplace_back(a, b);
    }
    sort(board.begin(), board.end());
    int begin = 0;
    int sum = 0;
    for (int i = 1; i < N; i++)
    {
        auto &prev = board[begin];
        auto &current = board[i];
        if (prev.second < current.first)
        {
            sum += prev.second - prev.first;
            begin = i;
        }
        else if (prev.second >= current.first)
        {
            prev.second = max(prev.second, current.second);
        }
    }
    cout << sum + board[begin].second - board[begin].first;
}