#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
using namespace std;

vector<int> bs;
map<int, vector<int>> dic;
int n, t;

int cached[100001][2];

int dp(int root, int idx, map<int, vector<int>>::iterator it, int same_count)
{
    int &ret = cached[idx][bs[root] == bs[idx]];
    if (ret == -1)
    {
        ret = 1;
        int value = bs[idx];
        int idx_lo = lower_bound(dic[value].begin(), dic[value].end(), idx) - dic[value].begin();
        // same value test
        if (idx_lo + 1 < (int)dic[value].size())
        {
            ret = max(ret, dp(root, dic[value][idx_lo + 1], it, same_count + 1) + 1);
        }
        it++;
        // next value
        if (it != dic.end() && (bs[root] == value || (bs[root] != value && same_count == (int)dic[value].size())))
        {
            int n_f_idx = it->second[0];
            int n_value = bs[n_f_idx];
            int n_idx_lo = lower_bound(dic[n_value].begin(), dic[n_value].end(), idx) - dic[n_value].begin();
            if (n_idx_lo < (int)dic[n_value].size())
            {
                ret = max(ret, dp(root, dic[n_value][n_idx_lo], it, 1) + 1);
            }
        }
    }
    return ret;
}

int solve()
{
    int answer = bs.size();

    for (auto it = dic.begin(); it != dic.end(); it++)
    {
        int idx = it->second[0];
        int length = dp(idx, idx, it, 1);
        answer = min(answer, static_cast<int>(bs.size()) - length);
    }
    return answer;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //   freopen("input.txt", "r", stdin);

    cin >> n;
    bs.resize(n);
    dic.clear();
    memset(cached, -1, sizeof cached);
    for (int i = 0; i < n; i++)
    {
        cin >> bs[i];
        dic[bs[i]].push_back(i);
    }
    cout << solve() << "\n";
}