#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#define COUT(a) cout << a << "\n"
#define CCOUT(a, b) cout << a << b << "\n"
#define CCCOUT(a, b, c) cout << a << b << c << "\n"

using namespace std;

vector<int> A;
map<int, int> dic_A;

bool idx_to_i(int idx, int i, int k)
{
    int first_changer = (abs(idx) <= (int)A.size() - 1 - idx) ? A.size() - 1 : 0;
    if (abs(first_changer - idx) < k)
    {
        return false;
    }
    int idx_idx = A[idx];
    int f_idx = A[first_changer];
    int i_idx = A[i];

    swap(A[idx], A[first_changer]);

    swap(A[first_changer], A[i]);
    dic_A[f_idx] = idx;
    dic_A[idx_idx] = i;
    dic_A[i_idx] = first_changer;

    if (first_changer < i)
    {
        swap(A[idx], A[first_changer]);
        dic_A[i_idx] = idx;
        dic_A[f_idx] = first_changer;
    }
    return true;
}

string solve(int k)
{
    bool is_can = true;
    auto it = dic_A.begin();
    for (int i = 0; i < A.size(); i++, it++)
    {
        int idx = it->second;
        if (idx == i)
            continue;
        if (!idx_to_i(idx, i, k))
        {
            is_can = false;
            break;
        }
    }
    if (is_can)
    {
        return "YES";
    }
    else
    {
        return "NO";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    while (T--)
    {
        int n, x;
        cin >> n >> x;
        A.resize(n);
        dic_A.clear();
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
            dic_A[A[i]] = i;
        }
        COUT(solve(x));
    }
}