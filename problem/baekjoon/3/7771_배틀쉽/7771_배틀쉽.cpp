
// s:
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

// 한 칸 크기의 전함 4척,
// 두 칸 크기의 전함 3척,
// 세 칸 크기의 전함 2척,
// 네 칸 크기의 전함 1척,
// 총 10척의 우주 전함을 보드 위에 배치
// 각 전함 => 수직 혹은 수평으로 이어진 칸들의 연속된 집합 (좌우 상하 대각선으로
// 인접 불가, 어떤 칸을 공유할 수 없음)

// 보드를 세팅 => 몇 라운드를 거쳐 테스트를 진행
// 라운드당 하나의 칸 => 발포
// 전함에 해당하는 모든 칸 x => 전함이 파괴
// 게임을 가장 복잡하게 만드는 보드의 초기 상태를 구하는 프로그램을 작성하라

int main()
{
    std::vector<std::vector<int>> board(10, std::vector<int>(10, 0));
    std::priority_queue<std::pair<int, std::pair<int, int>>> pq;
    std::vector<int> ships = {4, 3, 3, 2, 2, 2, 1, 1, 1, 1};
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            std::cin >> board[i][j];
            pq.emplace(board[i][j], std::make_pair(i, j));
        }
    }
    auto isOkay = [&](int i, int j) {
        for (int x = -1; x < 2; x++)
        {
            for (int y = -1; y < 2; y++)
            {
                int yy = i + y;
                int xx = j + x;
                if (yy < 10 && xx < 10 && yy > -1 && xx > -1)
                {
                    if (board[yy][xx] == -1)
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    };
    auto setShip = [&](int i, int j, int count) {
        std::pair<int, int> direction[4] = {{0, 1}, {1, 0}};
        for (int axis = 0; axis < 2; axis++)
        {
            int okCount = 0;
            for (int k = 0; k < count; k++)
            {
                int y = i + direction[axis].first * k;
                int x = j + direction[axis].second * k;
                if (y < 10 && x < 10 && y > -1 && x > -1)
                {
                    if (isOkay(y, x))
                        okCount++;
                }
            }
            if (count == okCount)
            {
                for (int k = 0; k < count; k++)
                {
                    int y = i + direction[axis].first * k;
                    int x = j + direction[axis].second * k;
                    board[y][x] = -1;
                }
                return true;
            }
        }
        return false;
    };
    while (!ships.empty())
    {
        auto item = pq.top();
        pq.pop();
        int i = item.second.first;
        int j = item.second.second;
        if (setShip(i, j, ships[ships.size() - 1]))
        {
            ships.pop_back();
        }
    }

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            std::cout << ((board[i][j] == -1) ? '#' : '.');
        }
        std::cout << std::endl;
    }
}