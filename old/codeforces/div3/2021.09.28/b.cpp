#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

// a[1...n] = [a1, a2, ..., am]
// 1. select index l and r 1 ~ n
// 2. replace seg[l~r] to left offset d

// output : l r d

// sort

void rotate(vector<int> &el, int lo, int hi, int k)
{
    vector<int> tmp(el.begin() + lo, el.begin() + hi);
    auto it = tmp.end();
    tmp.insert(it, el.begin() + lo, el.begin() + hi);
    k %= (tmp.size() / 2);
    for (int i = lo, h = k; i < hi; i++, h++)
    {
        el[i] = tmp[h];
    }
}

int N;
vector<vector<int>> solve(vector<int> &el)
{
    vector<vector<int>> ret;
    for (int i = 0; i < N; i++)
    {
        int min = min_element(el.begin() + i, el.end()) - el.begin();
        if (min != i)
        {
            rotate(el, i, N, min - i);
            ret.push_back({i + 1, N, min - i});
        }
        else
        {
            continue;
        }
    }
    return ret;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> N;
        vector<int> el;
        el.resize(N);
        for (int i = 0; i < N; i++)
        {
            cin >> el[i];
        }

        vector<vector<int>> els = move(solve(el));
        cout << els.size() << "\n";
        for (int i = 0; i < els.size(); i++)
        {
            for (int j = 0; j < els[i].size(); j++)
            {
                cout << els[i][j] << " ";
            }
            cout << "\n";
        }
    }
}