/**

풀이:
달팽이 배열을 그리는 인덱스를 저장함
블리자드는 2차원에서
loop(move => explosion) 는 1차원, 끝인덱스를 넘겨주어 최적화
change는 두번 순회, 첫번째는 정보 수집, 두번째는 새롭게 구슬을 생성

**/
#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <cstring>

using namespace std;

class Board
{
    struct Index
    {
        int y;
        int x;
    };

public:
    int g_count[4];

private:
    int A[101][101];
    int N;
    vector<Index> indecies;
    vector<pair<int, Index>> sameStack;

public:
    Board(int inN)
        : N(inN)
    {
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};
        int dir = 0;
        int visited[101][101];
        memset(visited, 0, sizeof visited);
        int x = 0, y = 0;
        while (indecies.size() < N * N - 1)
        {
            visited[y][x] = 1;
            indecies.push_back({y, x});
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (visited[ny][nx] == 1 || !isBoundary(nx, ny))
            {
                dir = (dir + 1) % 4;
            }
            x += dx[dir];
            y += dy[dir];
        }

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cin >> A[i][j];
                if (A[i][j] == 0 && !(i == N / 2 && j == N / 2))
                {
                    A[i][j] = -1;
                }
            }
        }
        printDebug("init");
    }
    void printDebug(std::string msg = "")
    {
        return;
        cout << msg << "=====================\n";
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (A[i][j] >= 0)
                {
                    cout << " ";
                }
                cout << A[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "=====================\n";
    }
    bool isBoundary(int x, int y)
    {
        return x >= 0 && x < N && y >= 0 && y < N;
    }

    void blizzard(int dir, int dist)
    {
        const int dx[] = {0, 0, 0, -1, 1};
        const int dy[] = {0, -1, 1, 0, 0};
        for (int i = 1; i <= dist; i++)
        {
            int nx = N / 2 + dx[dir] * i;
            int ny = N / 2 + dy[dir] * i;
            if (!isBoundary(nx, ny))
            {
                break;
            }
            A[ny][nx] = -1;
        }
        printDebug("blizzard");
    }
    int move(int endIdx)
    {
        int count = 0;
        int backIdx = endIdx;
        for (int i = (int)indecies.size() - 1; i >= endIdx; i--)
        {
            auto [y, x] = indecies[i];
            auto [ny, nx] = indecies[i + count];
            if (A[y][x] == -1)
            {
                count++;
                continue;
            }
            swap(A[y][x], A[ny][nx]);
            backIdx = i + count;
        }
        printDebug("moveAndExplosion");
        return backIdx;
    }
    void stackPop(int y, int x)
    {
        if (!sameStack.empty() && sameStack.back().first != A[y][x])
        {
            if (sameStack.size() >= 4)
            {
                auto [num, idx] = sameStack.back();
                for (int j = 0; j < sameStack.size(); j++)
                {
                    auto [num1, idx1] = sameStack[j];
                    A[idx1.y][idx1.x] = -1;
                }
                g_count[num] += sameStack.size();
            }
            sameStack.clear();
        }
    }
    void explosion(int endIdx)
    {
        for (int i = (int)indecies.size() - 1; i >= endIdx; i--)
        {
            auto [y, x] = indecies[i];
            stackPop(y, x);
            sameStack.push_back({A[y][x], {y, x}});
        }
        stackPop(N / 2, N / 2);
    }
    void moveAndExplosion()
    {
        int moveEndIdx = 0, endIdx = -1;
        while (true)
        {
            endIdx = move(moveEndIdx);
            if (endIdx == moveEndIdx)
                break;
            explosion(endIdx);
            moveEndIdx = endIdx;
        }
    }

    void change()
    {
        vector<int> newValue;
        for (int i = indecies.size() - 1; i >= 0; --i)
        {
            auto [y, x] = indecies[i];
            if (!sameStack.empty() && sameStack.back().first != A[y][x])
            {
                newValue.push_back(sameStack.size());
                newValue.push_back(sameStack.back().first);
                sameStack.clear();
            }
            if (A[y][x] != -1)
                sameStack.push_back({A[y][x], {y, x}});
        }
        int j = 0;
        for (int i = indecies.size() - 1; i >= 0; --i)
        {
            auto [y, x] = indecies[i];
            if (j < newValue.size())
                A[y][x] = newValue[j++];
        }
        printDebug();
    }
    void printAnswer()
    {
        cout << g_count[1] + g_count[2] * 2 + g_count[3] * 3;
    }
};

int main()
{
    int N, M;
    cin >> N >> M;

    Board board(N);

    for (int i = 0; i < M; i++)
    {
        int dir, dist;
        cin >> dir >> dist;
        board.blizzard(dir, dist);
        board.moveAndExplosion();
        board.change();
    }
    board.printAnswer();
}
