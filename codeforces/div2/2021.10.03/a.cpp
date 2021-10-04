#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#define COUT(a) cout << a << "\n"
#define CCOUT(a, b) cout << a << b << "\n"
#define CCCOUT(a, b, c) cout << a << b << c << "\n"

using namespace std;
int N, H;
vector<int> A;
// 1e9

// 공격횟수
//int cached[1001];
int solve()
{
    int common = H / (A[0] + A[1]);
    int p = H % (A[0] + A[1]);
    int adder = 0;
    if (p > A[0])
    {
        adder = 2;
    }
    else if (p > 0)
    {
        adder = 1;
    }
    //   COUT("anser:");
    //   COUT(p);
    //   COUT(adder);
    //   COUT(common);
    return common * 2 + adder;
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
        cin >> N >> H;
        A.resize(N);
        for (int i = 0; i < N; i++)
        {
            cin >> A[i];
        }
        sort(A.begin(), A.end(), [](int &a, int &b)
             { return a > b; });
        cout << solve() << "\n";
    }
}