// s:
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <cstring>
#include <string>
#include <functional>

int main()
{
    int N;
    std::cin >> N;
    std::vector<std::pair<int, int>> board;
    std::priority_queue<int> pq;
    int current = 0;
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        int a, b;
        std::cin >> a >> b;
        board.emplace_back(a, b);
    }
    std::sort(board.begin(), board.end());
    for (int i = 0; i < N; i++)
    {
        int deadline = board[i].first;
        int reward = board[i].second;
        if (current < deadline)
        {
            pq.push(-reward);
            current++;
            sum += reward;
        }
        else if (-pq.top() < reward)
        {
            sum -= -pq.top();
            pq.pop();
            pq.push(-reward);
            sum += reward;
        }
    }
    std::cout << sum;
}