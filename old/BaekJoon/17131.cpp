#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>

#include <queue>

using namespace std;
using pii = pair<int, int>;
using ll = long long;

vector<pii> point; // y, x
int maxN = 0;

struct RQ
{
    using ll = int;
    const ll OUT_OF_BOUNDS_ = 0;

    int n;
    vector<ll> range;
    RQ(int m)
    {
        n = m;
        range.resize(n * 4 + 4, 0);
    }
    ll op(ll a, ll b)
    {
        return a + b;
    }
    ll query(int left, int right, int node, int nodeLeft, int nodeRight)
    {
        if (right < nodeLeft || nodeRight < left)
            return OUT_OF_BOUNDS_;
        if (left <= nodeLeft && nodeRight <= right)
            return range[node];
        int mid = (nodeLeft + nodeRight) / 2;
        return op(query(left, right, node * 2, nodeLeft, mid),
                  query(left, right, node * 2 + 1, mid + 1, nodeRight));
    }
    ll query(int left, int right)
    {
        return query(left, right, 1, 0, n - 1);
    }
    ll update(int index, ll newValue, int node, int nodeLeft, int nodeRight)
    {
        if (index < nodeLeft || nodeRight < index)
            return range[node];
        if (nodeLeft == nodeRight)
            return range[node] = newValue;
        int mid = (nodeLeft + nodeRight) / 2;
        return range[node] = op(
                   update(index, newValue, node * 2, nodeLeft, mid),
                   update(index, newValue, node * 2 + 1, mid + 1, nodeRight));
    }
    ll update(int index, int newValue)
    {
        return update(index, newValue, 1, 0, n - 1);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    point.clear();
    point.resize(n);
    map<int, int> dic;
    for (int i = 0; i < n; i++)
    { // x , y
        cin >> point[i].second >> point[i].first;
        dic[point[i].second]++;
    }
    sort(point.begin(), point.end(), [](pii &a, pii &b)
         {
                 if (a.first == b.first)
                 {
                     return a.second < b.second;
                 }
                 else
                 {
                     return a.first > b.first;
                 } });
    for (auto it = dic.begin(); it != dic.end(); it++)
    {
        it->second = maxN++;
    }
    for (auto &p : point)
    {
        p.second = dic[p.second];
    }
    RQ rq(maxN);

    ll answer = 0ll;
    const ll MOD = 1e9 + 7;
    vector<pair<int, int>> s;
    s.push_back(point[0]);
    for (int i = 1; i < n; i++)
    {
        int mid = point[i].second;
        //  cout << "y : " << point[i].first << " x : " << mid << "\n ";
        while (!s.empty() && (s.back().first != point[i].first))
        {
            int x = s.back().second;
            rq.update(x, rq.query(x, x) + 1);
            s.pop_back();
        }
        ll left = rq.query(0, mid - 1);
        ll right = rq.query(mid + 1, maxN - 1);
        // cout << "    left: " << left << " " << right << "\n";
        answer = (answer + (left * right)) % MOD;

        s.push_back(point[i]);
    }

    cout << answer << "\n";
}