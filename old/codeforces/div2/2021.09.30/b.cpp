#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#define COUT(a) cout << a << "\n"
#define CCOUT(a, b) cout << a << b << "\n"
#define CCCOUT(a, b, c) cout << a << b << c << "\n"

using namespace std;
// n = node , m = edge
// k - 1 보다 작아야한다 직경
// self - loop 또는 다수의 엣지 x (두개 사이에는 하나의 엣지)
//  그래프 직경 = 두노드 사이의 최대 거리 (모든 최소거리를 찾고 최대인 거리)
// 두 노드 사이의 거리는 최소 엣지거리
// -> 이런 그래프 생성

bool cons_graph(int n, int m, int k)
{
    int m2 = n - 1;
    int m1 = 0;
    for (int i = 1; i < n; i++)
    {
        m1 += i;
    }
    // cout << "m : " << m << " edge:" << m2 << " " << m1 << "\n";
    if (m1 < m)
    {
        return false;
    }
    if (k >= 2 && m2 <= m)
    {
        return true;
    }
    if (k >= 1 && m1 == m)
    {
        return true;
    }
    if (k >= 0 && n == 1 && m == 0)
    {
        return true;
    }
    return false;
}

string solve(int n, int m, int k)
{
    if (k - 2 >= 0 && cons_graph(n, m, k - 2))
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
        int n, m, k;
        cin >> n >> m >> k;
        COUT(solve(n, m, k));
    }
}