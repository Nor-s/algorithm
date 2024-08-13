// y 는 감소 해야하고 x는  증가해야한다.
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#include <map>

using namespace std;
using pii = pair<int, int>;
using ll = long long;

vector<pii> point; // x, y
int n;
int maxN = 0;

struct RQ
{
    vector<int> seg;
    RQ(int n)
    {
        seg.clear();
        seg.resize(n * 4 + 4, 0);
    }
    int query(int lo, int hi, int idx, int qlo, int qhi)
    {
        if (hi < qlo || qhi < lo)
        {
            return 0;
        }
        if (qlo <= lo && hi <= qhi)
        {
            return seg[idx];
        }

        int mid = (lo + hi) / 2;
        int left = query(lo, mid, idx * 2, qlo, qhi);
        int right = query(mid + 1, hi, idx * 2 + 1, qlo, qhi);
        return left + right;
    }
    int update(int lo, int hi, int idx, int pos)
    {
        if (hi < pos || lo > pos)
        {
            return seg[idx];
        }
        if (lo == hi)
        {
            return seg[idx] = seg[idx] + 1;
        }
        int mid = (lo + hi) / 2;
        int left = update(lo, mid, idx * 2, pos);
        int right = update(mid + 1, hi, idx * 2 + 1, pos);
        return seg[idx] = left + right;
    }
};

ll solve()
{
    ll answer = 0;
    RQ rq(maxN);

    for (int i = 0; i < point.size(); i++)
    {
        answer += (ll)rq.query(0, maxN, 1, 0, point[i].second);
        rq.update(0, maxN, 1, point[i].second);
    }
    return answer;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        maxN = 0;
        cin >> n;
        point.clear();
        point.resize(n);
        map<int, int> dic;
        for (int i = 0; i < n; i++)
        { // x , y
            cin >> point[i].first >> point[i].second;
            dic[point[i].second]++;
        }
        sort(point.begin(), point.end(), [](pii &a, pii &b)
             {
                 if (a.first == b.first)
                 {
                     return a.second > b.second;
                 }
                 else
                 {
                     return a.first < b.first;
                 }
             });
        for (auto it = dic.end(); it != dic.begin();)
        {
            it--;
            it->second = maxN++;
        }
        for (auto &p : point)
        {
            p.second = dic[p.second];
        }
        cout << solve() << "\n";
    }
}