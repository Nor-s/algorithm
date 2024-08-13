#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int N; // 1 <= <= 1024
int M; //1 <=  <= 100,000
int nn[1024][1024];

/*
4 3
1 2 3 4
2 3 4 5
3 4 5 6
4 5 6 7
2 2 3 4
3 4 3 4
1 1 4 4  
*/
using ull = unsigned int;
ull sum[1024][1024];

ull get_sum(int x1, int y1, int x2, int y2)
{
    ull left = 0;
    ull upper = 0;
    ull corner = 0;
    if (x1 - 1 >= 0)
    {
        left = sum[x1 - 1][y2];
    }
    if (y1 - 1 >= 0)
    {
        upper = sum[x2][y1 - 1];
    }
    if (x1 - 1 >= 0 && y1 - 1 >= 0)
    {
        corner = sum[x1 - 1][y1 - 1];
    }
    return sum[x2][y2] - left - upper + corner;
}
void init()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            ull upper = 0;
            ull left = 0;
            ull corner = 0;
            if (i - 1 >= 0)
            {
                left = sum[i - 1][j];
            }
            if (j - 1 >= 0)
            {
                upper = sum[i][j - 1];
            }
            if (i - 1 >= 0 && j - 1 >= 0)
            {
                corner = sum[i - 1][j - 1];
            }

            sum[i][j] = upper + left - corner + nn[i][j];
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> nn[i][j];
        }
    }
    init();
    for (int i = 0; i < M; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--, x2--, y1--, y2--;
        cout << get_sum(x1, y1, x2, y2) << "\n";
    }
}