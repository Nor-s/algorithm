#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <queue>
#define cout1(a) cout << a
#define cout2(a, b) cout << a << b
#define cout3(a, b, c) cout << a << b << c
#define cout4(a, b, c, d) cout << a << b << c << d
#define cout5(a, b, c, d, e) cout << a << b << c << d << e

using namespace std;

vector<set<int>> adjList;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    while (T--)
    {
        int n, k;
        cin >> n >> k;
        adjList.clear();
        adjList.resize(n);
        queue<pair<int, int>> q;
        // 입력
        for (int i = 0; i < n - 1; i++)
        {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            adjList[a].insert(b);
            adjList[b].insert(a);
        }
        // 잎들을 queue에 넣는다.
        for (int i = 0; i < n; i++)
        {
            if (adjList[i].size() <= 1)
            {
                q.push({0, i});
            }
        }

        int answer = 0;
        // bfs
        while (!q.empty())
        {
            auto [d, here] = q.front();
            q.pop();
            // K번째에 도달
            if (d == k)
            {
                break;
            }
            answer++;
            // 만약 간선이 0 인 노드이면 계속 계산할 필요가 없다.
            if (adjList[here].size() == 0)
            {
                answer = n; // 두개의 노드들만 있을 경우 노드 한개가 큐에 두번들어가게된다.
                continue;
            }
            int b = *adjList[here].begin();

            adjList[b].erase(here);
            if (adjList[b].size() <= 1)
            {
                q.push({d + 1, b});
            }
        }
        cout << n - answer << "\n";
    }
}