#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
#include <cstring>

using namespace std;
// 544
// 10:11

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
}