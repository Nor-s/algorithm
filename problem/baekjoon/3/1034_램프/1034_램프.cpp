// https://www.acmicpc.net/problem/1034
// s:
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <bitset>
#include <any>

enum
{
    BIT_SIZE = 50
};

void flipColumn(std::vector<std::bitset<BIT_SIZE>> &lamptable, size_t column)
{
    for (int i = 0; i < lamptable.size(); i++)
    {
        lamptable[i].flip(column);
    }
}

size_t allCount(std::vector<std::bitset<BIT_SIZE>> &lamptable)
{
    size_t count = 0;
    for (int i = 0; i < lamptable.size(); i++)
    {
        count += lamptable[i].all();
    }
    return count;
}

class LampController
{
public:
    LampController(std::vector<std::bitset<BIT_SIZE>> &lamptable, size_t index,
                   int K)
        : m_lamptable(lamptable)
    {
        for (int i = 0; i < m_lamptable[index].size(); i++)
        {
            if (!m_lamptable[index][i])
            {
                K--;
                m_onLampPos.push_back(i);
                flipColumn(m_lamptable, i);
            }
        }
        m_bCanTurnOn = (K >= 0 && K % 2 == 0);
    }
    ~LampController()
    {
        for (int i = 0; i < m_onLampPos.size(); i++)
        {
            flipColumn(m_lamptable, m_onLampPos[i]);
        }
    }
    bool canTurnOn() const
    {
        return m_bCanTurnOn;
    }

private:
    std::vector<std::bitset<BIT_SIZE>> &m_lamptable;
    std::vector<size_t> m_onLampPos;
    bool m_bCanTurnOn = true;
};

void solve(std::vector<std::bitset<BIT_SIZE>> &lamptable, size_t K)
{
    size_t answer = 0;
    for (int i = 0; i < lamptable.size(); i++)
    {
        if (LampController lampController(lamptable, i, K);
            lampController.canTurnOn())
        {
            answer = std::max(answer, allCount(lamptable));
        }
    }
    std::cout << answer << std::endl;
}

void input(size_t &H, size_t &W, std::vector<std::bitset<BIT_SIZE>> &lamptable,
           size_t &K)
{
    std::cin >> H >> W;
    lamptable.resize(H, std::bitset<BIT_SIZE>(INT64_MAX));
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            char c;
            std::cin >> c;
            lamptable[i].set(j, c == '1');
        }
    }
    std::cin >> K;
}

int main()
{
    size_t H, W, K;
    std::vector<std::bitset<BIT_SIZE>> lamptable;

    input(H, W, lamptable, K);
    solve(lamptable, K);
}