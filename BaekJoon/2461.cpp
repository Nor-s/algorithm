#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
#include <cstring>

using namespace std;
// 544

/*

N개의 학급
- 각 학급은 M명
- 한반에서 한명의 대표선수 선발
- 각각의 반에서 대표로 선발된 학생들의 능력치 중 최대 최소값의 차이가 최소
*/
int N, M;
vector<pair<long long, long long>> students;
vector<long long> classes;
long long cached[1001][1001];

long long bt(int i, int j)
{
    if (i >= j)
    {
        return INT32_MAX;
    }
    long long &ret = cached[i][j];
    if (ret == -1)
    {
        ret = INT32_MAX;
        if (students[i].second != students[j].second)
        {
            ret = min(ret, students[j].first - students[i].first);
        }

        if (classes[students[i].second] + 1 < M)
        {
            classes[students[i].second] += 1;
            ret = min(ret, bt(i + 1, j));
            classes[students[i].second] -= 1;
        }
        if (classes[students[j].second] + 1 < M)
        {
            classes[students[j].second] += 1;
            ret = min(ret, bt(i, j - 1));
            classes[students[j].second] -= 1;
        }
    }
    return ret;
}

int main()
{
    cin >> N >> M;
    memset(cached, -1, sizeof cached);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int tmp;
            cin >> tmp;
            students.push_back({tmp, i});
        }
    }
    sort(students.begin(), students.end());
    classes.resize(N, 0);

    int minI = 0;
    int maxI = students.size() - 1;
    if (N == 1)
    {
        cout << 0;
    }
    else
    {
        cout << bt(minI, maxI);
    }
}