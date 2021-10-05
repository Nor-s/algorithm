#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

vector<int> balls;
vector<pair<int, int>> sorted_balls;

int solve()
{
    int answer = balls.size();
    for (int i = 0; i < sorted_balls.size(); i++)
    {
        int order = sorted_balls[i].second;
        int length = 1;
        //  cout << "sorted: " << sorted_balls[i].first << " " << order << "\n";
        for (int j = i + 1; j < balls.size(); j++)
        {
            int order2 = sorted_balls[j].second;
            if (balls[order] == balls[order2] && j == i + 1 && order + 1 != order2)
            {
                continue;
            }
            else if (order < order2)
            {
                //      cout << "     " << balls[order2] << " " << order2 << "\n";
                length++;
                order = order2;
            }
            else
            {
                while (j + 1 < balls.size() && sorted_balls[j].first == sorted_balls[j + 1].first && order > sorted_balls[j].second)
                {
                    j++;
                }
                if (order2 != sorted_balls[j].second)
                {
                    j--;
                    continue;
                }
                else
                {
                    break;
                }
            }
        }
        //    cout << "    " << length << "\n";
        answer = min(answer, static_cast<int>(balls.size()) - length);
    }
    return answer;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    int n;
    cin >> n;
    balls.resize(n);
    sorted_balls.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> balls[i];
        sorted_balls[i] = {balls[i], i};
    }
    sort(sorted_balls.begin(), sorted_balls.end());
    cout << solve();
}