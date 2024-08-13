#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, k;

vector<int> a;
// 08 43

struct rq
{
    vector<int> seg;
    priority_queue<int> pq;
    int size;
    rq(int n)
    {
        size = n;
        seg.resize(4 * n + 4, 0);
    }
    int init(const vector<int> v, int lo, int hi, int node_idx)
    {
        if (lo == hi)
        {
            pq.push(v[lo]);
            return seg[node_idx] = v[lo];
        }
        int mid = (lo + hi) / 2;
        int left = init(v, lo, mid, node_idx * 2);
        int right = init(v, mid + 1, hi, node_idx * 2 + 1);
        seg[node_idx] = left + right;
        pq.push(seg[node_idx]);
        return seg[node_idx];
    }
    int update(int i, int x, int lo, int hi, int node_idx)
    {
        if (lo > i || hi < i)
        {
            return seg[node_idx];
        }
        if (lo == hi)
        {
            return seg[node_idx] = x;
        }

        int mid = (lo + hi) / 2;
        int left = update(i, x, lo, mid, node_idx * 2);
        int right = update(i, x, mid + 1, hi, node_idx * 2 + 1);
        seg[node_idx] = left + right;

        return seg[node_idx];
    }
    void update(int i, int x)
    {
        update(i, x, 0, size - 1, 1);
    }
    int pop()
    {
        int ret = pq.top();
        pq.pop();
        return ret;
    }
};

int main()
{
    cin >> n >> k;
    a.resize(n);
    rq rqq(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    rqq.init(a, 0, n - 1, 1);
    for (int i = 0; i < k; i++)
    {
        cout << rqq.pop() << " ";
    }
}