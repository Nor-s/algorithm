#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>

#define cout1(a) cout << a
#define cout2(a, b) cout << a << b
#define cout3(a, b, c) cout << a << b << c
#define cout4(a, b, c, d) cout << a << b << c << d
#define cout5(a, b, c, d, e) cout << a << b << c << d << e

using namespace std;
// 1move -> one can select any single digit  remove it
// 정수 한개면 제거못함
// 임의의 하나선택 제거
//  0들 앞에오면 자동적으로 제거
// 25 로 나눠질 수 있는 수 최소 스텝 개수
// 답이존재함 무조건
// 입력의 크기 너무 큼

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    while (T--)
    {
        string a;
        cin >> a;
        reverse(a.begin(), a.end());
        int answer[4] = {1111, 1111, 1111, 1111};
        map<int, vector<int>> dic;
        for (int i = 0; i < a.size(); i++)
        {
            dic[a[i] - '0'].push_back(i);
        }
        pair<int, int> find[] = {{2, 5}, {5, 0}, {7, 5}, {0, 0}};
        for (int i = 0; i < 4; i++)
        {
            auto [s, f] = find[i];
            if ((dic[f].size() > 0 && dic[s].size() > 0) || (dic[f].size() > 1 && f == 0 && s == 0))
            {
                int ff = dic[f][0];
                auto ss = lower_bound(dic[s].begin(), dic[s].end(), ff + 1);
                if (ss != dic[s].end())
                {
                    answer[i] = ff + (*ss - ff - 1);
                }
            }
        }
        cout << *min_element(&answer[0], &answer[0] + 4) << "\n";
    }
}