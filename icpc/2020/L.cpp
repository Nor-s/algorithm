#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
// 1000

using namespace std;
int n;
string before;
string after;
int l, r;
char finger[2];

int cached[10001][3];

int is_can(int idx, int count)
{
    //  cout << idx << " " << count << " <---\n";
    if (idx == after.size())
    {
        return 0;
    }
    int &ret = cached[idx][abs(count)];
    if (ret != -1)
    {
        //    cout << "ret : " << ret << "\n";
        return ret;
    }
    ret = -1e8;
    if (abs(count) < 2 && finger[abs(count)] == after[idx])
    {
        //   cout << "finger\n";
        // cout << finger[abs(count)] << " " << after[idx] << "\n";
        ret = max(ret, is_can(idx + 1, count - 1) + 1);
    }
    if (idx + count < before.size() && before[idx + count] == after[idx])
    {
        //       cout << before[idx + count] << " " << after[idx] << "\n";
        ret = max(ret, is_can(idx + 1, count) + 1);
    }
    return ret;
}
string solve()
{
    int answer = is_can(0, 0);
    // cout << answer << "\n";
    if (answer == after.size())
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
    cin >> n;
    cin >> before;
    cin >> after;
    cin >> l >> r;
    memset(cached, -1, sizeof cached);
    finger[0] = before[l], finger[1] = before[r];
    before = before.substr(0, l) + before.substr(l + 1, r - 1 - l) + before.substr(r + 1);
    cout << solve();
}