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
int n; // even All students will be divided into two groups
// 각각 하나의 레슨 -> 5일중하나  the days chosen for the groups must be different
// 그룹들의 학생수는 같아야함
// 모든 학생들 -> 두 그룹으로 나눔
// the groups have equal sizes, and for each student,
// the chosen lesson day for their group is convenient.
//1 = can
// 0 = cannot

vector<vector<int>> student;
int twoday[5][5];
int oneday[5];

void solve()
{
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    while (T--)
    {
        cin >> n;
        student.clear();
        student.resize(n, vector<int>(5, 0));
        memset(twoday, 0, sizeof twoday);
        memset(oneday, 0, sizeof oneday);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                cin >> student[i][j];
                if (student[i][j] == 1)
                {
                    oneday[j]++;
                }
            }
            for (int j = 0; j < 5; j++)
            {
                if (student[i][j] == 0)
                    continue;
                for (int k = j + 1; k < 5; k++)
                {
                    if (student[i][k] == 1)
                    {
                        twoday[j][k]++;
                    }
                }
            }
        }
        /*
        cout1("-------\n");
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                cout << twoday[i][j] << " ";
            }
            cout << "\n";
        }
        */

        bool is_can = false;
        for (int i = 0; i < 5; i++)
        {
            if (is_can)
            {
                break;
            }
            for (int j = i + 1; j < 5; j++)
            {
                if (oneday[i] < n / 2 && oneday[j] < n / 2)
                {
                    continue;
                }
                int A = oneday[i] - twoday[i][j];
                int B = oneday[j] - twoday[i][j];
                if (A + B + twoday[i][j] == n && A + twoday[i][j] >= n / 2 && B + twoday[i][j] >= n / 2)
                {
                    is_can = true;
                }
            }
        }
        if (is_can)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}