// 8시 41분

// N개의 문제 => 문제 풀 때 컵라면 줌
// 데드라인도 있음
// 최대 컵라면 수는?
// 문제푸는데 단위시간 1
// 최대로 받을 수 있는 컵라면 수 = 2^31

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>

using namespace std;

int N;
vector<pair<int, int>> deadlineCup; // 200,000
int deadline = 0;
priority_queue<int> pq;

int main()
{
    cin >> N;
    deadlineCup.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> deadlineCup[i].first >> deadlineCup[i].second;
    }
    sort(deadlineCup.begin(), deadlineCup.end());
    for_each(deadlineCup.begin(), deadlineCup.end(), [](pair<int, int> &p)
             {
        if(deadline < p.first) {
            deadline++;
            pq.push(-p.second);
        }
        else if(-pq.top() < p.second) {
            pq.pop();
            pq.push(-p.second);
        } });
    int sum = 0;
    while (!pq.empty())
    {
        sum += -pq.top();
        pq.pop();
    }
    cout << sum;
}