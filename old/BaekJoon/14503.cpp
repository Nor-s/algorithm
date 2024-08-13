#include <iostream>

using namespace std;
int N, M;
int R, C, D;
int v[101][101];
int dx[4] = {0, 1, 0, -1}; // 북 동 남 서
int dy[4] = {-1, 0, 1, 0};
int gcount = 0;

int backDir(int dir)
{
    return (D + 2) % 4;
}
bool isInner(int y, int x)
{
    return !(y < 0 || y >= N || x < 0 || x >= M) &&
           v[y][x] != 1;
}
void debug()
{
    return;
    cout << "=====================\n";
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}
void clean()
{
    while (true)
    {
        debug();
        // 1
        if (v[R][C] == 0)
        {
            gcount++;
        }
        v[R][C] = 2;
        // 2
        int dirtyCount = 0;
        for (int i = 0; i < 4; i++)
        {
            int ny = R + dy[i];
            int nx = C + dx[i];
            if (!isInner(ny, nx))
                continue;
            if (v[ny][nx] == 0)
            {
                dirtyCount++;
            }
        }
        int nd = backDir(D);
        bool bHasDirty = dirtyCount > 0;
        if (bHasDirty)
        {
            D = (D + 3) % 4;
            nd = D;
        }
        int ny = R + dy[nd];
        int nx = C + dx[nd];
        if (!isInner(ny, nx))
        {
            if (bHasDirty)
            {
                continue;
            }
            return;
        }
        if (!bHasDirty || (bHasDirty && v[ny][nx] == 0))
        {
            R = ny;
            C = nx;
        }
    }
}

int main()
{
    cin >> N >> M;
    cin >> R >> C >> D;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int tmp;
            cin >> tmp;
            v[i][j] = tmp;
        }
    }
    clean();
    cout << gcount;
}
