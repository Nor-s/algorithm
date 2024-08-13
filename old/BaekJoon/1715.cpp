#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <utility>
#include <map>

using namespace std;

int main()
{
    int n;
    cin >> n;

    priority_queue<int> pq;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        pq.push(-tmp);
    }
    int ret = 0;
    while (pq.size() > 1)
    {
        int a = -pq.top();
        pq.pop();
        int b = -pq.top();
        pq.pop();
        pq.push(-(a + b));
        ret += a + b;
    }
    cout << ret;
}
