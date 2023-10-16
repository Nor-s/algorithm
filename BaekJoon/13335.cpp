#include <utility>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> v;
int main()
{
    int n, L, w;
    cin >> n >> L >> w;
    v.resize(n);
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }
    queue<pair<int, int>> q;
    int time = 0;
    int sum = 0;
    v.push_back(INT32_MAX / 2);
    for (int i = 0; i < v.size(); i++)
    {
        bool isupdate = false;
        if (!q.empty())
        {
            int diff = time - q.front().second;
            while (!q.empty() && diff > L)
            {
                sum -= q.front().first;
                q.pop();
                diff = time - q.front().second;
            }

            while (!q.empty() && sum + v[i] > w)
            {
                time += (L - diff + 1);
                isupdate = true;
                sum -= q.front().first;
                q.pop();
            }
        }
        q.push({v[i], time});
        sum += v[i];
        if (!isupdate)
            time++;
    }
    cout << time;
}