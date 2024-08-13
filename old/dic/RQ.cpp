#include <vector>

using namespace std;

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