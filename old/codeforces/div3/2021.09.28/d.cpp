#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>

#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            pq.push({a, i + 1});
        }

        vector<pair<int, int>> answer;
        pair<int, int> top1, top2;
        while (true)
        {
            top1 = pq.top();
            if (top1.first == 0)
            {
                break;
            }
            pq.pop();

            top2 = pq.top();
            if (top2.first == 0)
            {
                break;
            }
            pq.pop();

            pq.push({top1.first - 1, top1.second});
            pq.push({top2.first - 1, top2.second});

            answer.push_back({top1.second, top2.second});
        }

        cout << answer.size() << "\n";
        for (int i = 0; i < answer.size(); i++)
        {
            cout << answer[i].first << " " << answer[i].second << "\n";
        }
    }
}