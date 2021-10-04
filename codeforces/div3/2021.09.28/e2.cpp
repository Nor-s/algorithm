#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>

#include <queue>
// 4 50
using namespace std;
// min num inversions in the deque
// inversion i < j and di > dj

// time limit exceeded on test 3

struct RQ
{
    using ll = int;
    const ll OUT_OF_BOUNDS_ = 0;

    int n;
    vector<ll> range;
    RQ(const vector<ll> &array)
    {
        n = array.size();
        range.resize(n * 4 + 4);
        init(array, 0, n - 1, 1);
    }
    ll op(ll a, ll b)
    {
        return a + b;
    }
    ll init(const vector<ll> &array, int left, int right, int node)
    {
        if (left == right)
            return range[node] = array[left];
        int mid = (left + right) / 2;
        ll leftValue = init(array, left, mid, node * 2);
        ll rightValue = init(array, mid + 1, right, node * 2 + 1);
        return range[node] = op(leftValue, rightValue);
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

    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        long long answer = 0;
        vector<int> v(n);
        map<int, int> mp;

        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            mp[v[i]] = 1;
        }

        int value = 0;
        for (auto &it : mp)
        {
            it.second = value++;
        }
        RQ rq(vector<int>(n, 0));

        for (int i = 0; i < n; i++)
        {
            int mid = mp[v[i]];
            int left = rq.query(0, mid - 1);
            int right = rq.query(mid + 1, n - 1);
            answer += min(left, right);

            rq.update(mid, rq.query(mid, mid) + 1);
        }

        cout << answer << "\n";
    }
}
