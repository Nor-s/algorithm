// https://www.acmicpc.net/problem/1027
// s: 09:50
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

void check(int64_t startIndex, int64_t endIndex,
           std::vector<int64_t> &buildings, std::vector<int64_t> &result)
{
    std::pair<int64_t, int64_t> buildingA{startIndex, buildings[startIndex]};
    std::pair<int64_t, int64_t> buildingB{endIndex, buildings[endIndex]};
    std::pair<int64_t, int64_t> vectorAB{buildingB.first - buildingA.first,
                                         buildingB.second - buildingA.second};

    for (int64_t index = buildingA.first + 1; index < endIndex; index++)
    {
        std::pair<int64_t, int64_t> buildingC{index, buildings[index]};
        std::pair<int64_t, int64_t> vectorAC{buildingC.first - buildingA.first,
                                             buildingC.second -
                                                 buildingA.second};
        if (0 <=
            vectorAB.first * vectorAC.second - vectorAB.second * vectorAC.first)
        {
            return;
        }
    }
    result[startIndex]++;
    result[endIndex]++;
}

int main()
{
    int64_t N;
    std::cin >> N;

    std::vector<int64_t> building(N);
    std::vector<int64_t> result(N);

    std::for_each(building.begin(), building.end(),
                  [&](int64_t &n) { std::cin >> n; });

    for (int64_t startIndex = 0; startIndex < N; startIndex++)
    {
        for (int64_t endIndex = startIndex + 1; endIndex < N; endIndex++)
        {
            check(startIndex, endIndex, building, result);
        }
    }

    std::cout << *std::max_element(result.begin(), result.end());
}