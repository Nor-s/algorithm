#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>

using namespace std;

// start end
vector<int> a;

const int INF = 1e9 + 7;

int solve()
{
    int wnd[2][2001];
    int nxt = 1;
    int cur = 0;
    fill(&wnd[cur][0], &wnd[cur][0] + 2001, INF);
    wnd[cur][0] = 0;
    for (int i = 0; i < a.size(); i++)
    {
        fill(&wnd[nxt][0], &wnd[nxt][0] + 2001, INF);
        for (int left = 0; left < 2001; left++)
        {
            if (wnd[cur][left] == INF)
            {
                continue;
            }

            // plus
            if (left + a[i] < 2001)
            {
                int update = 0;
                // 범위 안
                if (left + a[i] < wnd[cur][left])
                {
                    update = wnd[cur][left];
                }
                // 확장
                else
                {
                    update = left + a[i];
                }
                wnd[nxt][left + a[i]] = min(wnd[nxt][left + a[i]], update);
            }

            // minus
            // 범위 안
            if (left - a[i] >= 0)
            {
                wnd[nxt][left - a[i]] = min(wnd[nxt][left - a[i]], wnd[cur][left]);
            }
            // 범위 밖 -> 확장가능성 -> 맨 왼쪽에 오게되니 0
            else
            {
                wnd[nxt][0] = min(wnd[nxt][0], wnd[cur][left] + a[i] - left);
            }
        }
        nxt = (nxt + 1) % 2;
        cur = (cur + 1) % 2;
    }
    return *min_element(&wnd[cur][0], &wnd[cur][0] + 2001);
}

/*
8
8 6 5 1 2 2 3 6
*/
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
        cin >> n; // the number of segments
        a.clear();
        a.resize(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        cout << solve() << "\n";
    }
}