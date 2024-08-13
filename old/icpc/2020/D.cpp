#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

// the sequence (8,5, 1, 3,4, 7, 6,2)
// three runs (8,5,1), (1,3,4,7), and (7,6,2)
// A sequence of distinct numbers whose every run has a length of at least 3 is said to be an UD-sequence.

// (8,5,1,3,4,7,6,2) is an UD-sequence, but (8,5,1,7,6,2,3,4) is not an UD-sequence
//  because it has a run (1,7) with length 2.

// 주어진 수열에서 부분수열을 만들고 가장긴 UD-sequence의 길이를 리턴하는문제
// UD-sequence는 증가 or 감소하는 부분의 길이가 최소 3이어야함
// (8,5,1,7,6,2,3,4) =>  (8,5,1,2,3,4)
// n (3 ≤ n ≤ 500,000)

// 11 02

struct rq
{
    struct node
    {
        int min_v{0};
        int max_v{0};
        int dec{0};
        int inc{0};
        node(int miv, int mav, int dc, int ic) : min_v(miv), max_v(mav), dec(dc), inc(ic) {}
    };
    vector<node> seg;
    rq(int n)
    {
        seg.resize(4 * n);
    }
    node init(vector<int> &a, int lo, int hi, int idx)
    {
        if (lo == hi)
        {
            return seg[idx] = node(a[lo], a[lo], 1, 1);
        }
        int mid = (lo + hi) / 2;
        node left = init(a, lo, mid, idx * 2);
        node right = init(a, mid + 1, hi, idx * 2 + 1);
    }
};

pair<int, pair<int, int>> cached[500001][2];
int dp(int idx, int n)
{
    for (int i = 0; i < n; i++)
    {
    }
}

// 일단 수열들
// 6 10
int main()
{
}