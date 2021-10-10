
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int N;
vector<int> A;
vector<int> B;

const long long MOD = 998244353;
// S = (s1, s2, s3 ... sn) <= == non decresing
// a<=b<=c
// 값 최대 3000
long long cached[3001][3001];
long long dp(int idx, int left)
{
    int dpp[2][3001];
    int cur = 0, nxt = 1;

    memset(&dpp[0][0], 1, sizeof dpp[0]);
    for (int i = 0; i < A.size(); i++)
    {
        int lo = A[i];
        int hi = B[i];
        // left
        for (int j = 0; j < 3001; i++)
        {
            if (dpp[cur][j] == 0)
            {
                continue;
            }
            dpp[cur][j];
            dpp[j] *= (hi - lo);
        }
        cur = (cur + 1) % 2;
        nxt = (nxt + 1) % 2;
    }

    return ret;
}
void solve()
{
    cout << dp(0, A[0]);
}
int main()
{
    cin >> N;
    A.resize(N);
    B.resize(N);
    memset(cached, -1, sizeof cached);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++)
    {
        cin >> B[i];
    }
    solve();
}