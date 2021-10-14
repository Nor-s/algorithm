#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;
// 844
//  곱한점수가 낮으면 => 종합순위에 앞섬
//   금은동, =>
//  같을경우 합산점수가 낮은 선수가 이김.
//  모두 같으면 등번호 낮은 선수가 이김

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> v;
    for (int i = 0; i < n; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        v.push_back({b * c * d, b + c + d, a});
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < 3; i++)
    {
        cout << v[i][2] << " ";
    }
}