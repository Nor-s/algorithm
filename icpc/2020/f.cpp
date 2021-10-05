#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N;
vector<pair<int, int>> pos;

// N 명의 경찰 , 도둑 한명 번갈아 움직임
// 도둑이 먼저 시작
// 경찰차례일땐 동ㅅ기에
// 상하좌우
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
// 도둑은 반드시 움직여야함
// 같은 격자. 최선/
// 영원히 잡히지 않으면 => 탈출가능한 조건
//  1 ≤ N ≤ 500,000
//  xi, yi, sx, sy의 범위는 −1e9 ≤ xi, yi, sx, sy ≤ 1e9이다.

pair<int, int> S;
vector<pair<int, int>> P;

// 외적
double cross(pair<int, int> &p1, pair<int, int> &p2)
{
    return p1.first * p2.second - p2.first * p1.second;
}

string solve()
{
    int answer[4] = {0, 0, 0, 0};
    for (int i = 0; i < P.size(); i++)
    {
        if (P[i].first == 0 && P[i].second == 0)
        {
            return "NO";
        }
        if (P[i].first <= 0 && P[i].second <= 0)
        {
            answer[2]++;
        }
        if (P[i].first <= 0 && P[i].second >= 0)
        {
            answer[1]++;
        }
        if (P[i].first >= 0 && P[i].second >= 0)
        {
            answer[0]++;
        }
        if (P[i].first >= 0 && P[i].second <= 0)
        {
            answer[3]++;
        }
    }
    if (answer[0] > 0 && answer[2] > 0)
    {
        return "NO";
    }
    if (answer[1] > 0 && answer[3] > 0)
    {
        return "NO";
    }
    return "YES";
}

int main()
{
    cin >> N;
    P.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> P[i].first >> P[i].second;
    }
    cin >> S.first >> S.second;
    for (int i = 0; i < N; i++)
    {
        P[i].first -= S.first;
        P[i].second -= S.second;
    }
    //  sort(P.begin(), P.end());
    cout << solve();
}