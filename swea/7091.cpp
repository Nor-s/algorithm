#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <tuple>
#include <iterator>
#include <map>
#include <set>
#include <cmath>
#include <queue>

#define cout1(a) cout << a
#define cout2(a, b) cout << a << b
#define cout3(a, b, c) cout << a << b << c
#define cout4(a, b, c, d) cout << a << b << c << d
#define cout5(a, b, c, d, e) cout << a << b << c << d << e
#define coutvi(a, b) copy(a, b, ostream_iterator<int>(cout, " "))
#define coutvc(a, b) copy(a, b, ostream_iterator<char>(cout, " "))

using namespace std;

int H, W, N, M;
vector<vector<char>> myPicture;
vector<vector<char>> picture;

void quadDiv(int y, int x, int size)
{
    if (size == 1)
    {
        return;
    }
    int half = size / 2;
    quadDiv(y - half, x - half, half);
    quadDiv(y - half, x + half, half);
    quadDiv(y + half, x - half, half);
    quadDiv(y + half, x + half, half);
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
        cin >> H >> W >> N >> M;
        myPicture = vector<vector<char>>(H, vector<char>(W));
        picture = vector<vector<char>>(N, vector<char>(M));
        for (int i = 0; i < H; i++)
            for (int j = 0; j < W; j++)
                cin >> myPicture[i][j];

        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                cin >> picture[i][j];
    }
}