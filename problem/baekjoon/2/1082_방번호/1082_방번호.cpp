
// s:
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

int main()
{
    int N;
    int money;
    std::cin >> N;
    std::vector<int> v(N);
    std::vector<std::pair<int, int>> sorted_v;
    for (size_t i = 0; i < N; i++)
    {
        std::cin >> v[i];
        sorted_v.emplace_back(v[i], i);
    }
    std::cin >> money;

    std::sort(sorted_v.begin(), sorted_v.end(),
              [](std::pair<int, int> &a, std::pair<int, int> &b) {
                  if (a.first == b.first)
                  {
                      return a.second > b.second;
                  }
                  return a.first < b.first;
              });
    std::vector<int> result;
    if (sorted_v[0].second == 0)
    {
        if (sorted_v.size() > 1 && money - sorted_v[1].first >= 0)
        {
            money -= sorted_v[1].first;
            result.push_back(sorted_v[1].second);
        }
        else
        {
            std::cout << 0;
            return 0;
        }
    }

    while (money - sorted_v[0].first >= 0)
    {
        result.push_back(sorted_v[0].second);
        money -= sorted_v[0].first;
    }

    for (int i = 0; i < result.size(); i++)
    {
        money += v[result[i]];
        int max_idx = result[i];
        for (int j = max_idx; j < N; j++)
        {
            int price = v[j];
            if (money - price >= 0)
            {
                max_idx = j;
            }
        }
        money -= v[max_idx];
        result[i] = max_idx;
    }

    for (int i = 0; i < result.size(); i++)
    {
        std::cout << result[i];
    }
}