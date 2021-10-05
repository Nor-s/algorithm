#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
using namespace std;

vector<int> bs;
vector<int> bbs;

int C[100001];

void push(int x, int lo, int hi, int &maxlen)
{
    int mid = (lo + hi) / 2;
    if (C[maxlen - 1] < x)
        C[maxlen++] = x;
    else if (lo + 1 == hi)
        C[hi] = x;
    else if (C[mid] >= x)
        return push(x, lo, mid, maxlen);
    else
        return push(x, mid, hi, maxlen);
}

void lis(vector<int> &alist, int ai, int &maxlen)
{
    if (ai == alist.size())
        return;

    int a = alist[ai];
    push(a, 0, maxlen, maxlen);
    return lis(alist, ai + 1, maxlen);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    bs.resize(n);
    bbs.resize(n);
    memset(C, -1, sizeof C);
    for (int i = 0; i < n; i++)
    {
        cin >> bs[i];
        bbs[i] = bs[i];
    }
    sort(bbs.begin(), bbs.end());
    cout << solve();
}