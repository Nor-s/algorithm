#include <iostream>
#include <vector>
#include <utility>

using namespace std;
// 10:01
int minY, maxY;
int n; // 1~100,000
int m;
vector<pair<int, int>> x; // left most

int solve(float q) {

}

int main()
{
    cin >> minY >> maxY;
    cin >> n;
    x.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i].first >> x[i].second;
    }
    cin >> m;
    for (int i = 0; i < n; i++)
    {
        float q;
        cin >> q;
        cout << solve(q);
    }
}