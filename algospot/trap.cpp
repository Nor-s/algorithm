#include <iostream>
#include <algorithm>
#include <utility>
#include <cstring>

using namespace std;

const int dx[] = {0,0, -1, 1, 0};
const int dy[] = {0,-1, 0, 0, 1};
int H, W;
char gameBoard[24][24];
bool visited[24][24];

void showGameBoard()
{
    for(int i = 2; i < H+2; i++)
    {
        for(int j = 2; j < W+2; j++)
           cout<<gameBoard[i][j];
        cout<<"\n";
    }
}
bool dfs(int y, int x, bool isRecursion)
{
    if(visited[y][x]) return false;

    for(int i = 0; i < 5; i++)
    {
        int count = 0;
        bool isCanSet = true;
        int yy = y+dy[i];
        int xx = x+dx[i];
        if(gameBoard[yy][xx] == '.')
        {
            if(isRecursion) 
            {
                isRecursion = false;
                continue;
            }
            if(visited[yy][xx])continue;
            gameBoard[yy][xx] = '^';
            visited[yy][xx] = true;
            for(int j = 1; j < 5; j++)
            {
                int yyy = yy + dy[j];
                int xxx = xx + dx[j];
                if(gameBoard[yyy][xxx] == '#') continue;

                if(gameBoard[yyy][xxx] == '^')
                {
                    gameBoard[yyy][xxx] = '.';
                    if(dfs(yyy, xxx, true))
                        isCanSet = isCanSet&&true;
                    else
                    {
                        isCanSet = false;
                        gameBoard[yyy][xxx] = '^';
                        count++;
                        break;
                    }
                }    
                count++;
            }
            if(isCanSet&&count > 0)
                return true;
            gameBoard[yy][xx] = '.';
        }
    }
    return false;
}

int solve()
{
    int ret = 0;
    for(int i = 2; i < H+2; i++)
        for(int j = 2; j < W+2; j++)
        {
            memset(visited, 0, sizeof visited);
            if(gameBoard[i][j] == '.')
                if(dfs(i, j, false)) ret++;
        }
    return ret;
}


int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int C;
    cin>>C;
    while(C--)
    {
        cin>>H>>W;
        for(int i = 2; i < H+2; i++)
            for(int j = 2; j < W+2; j++)
                cin>>gameBoard[i][j];
        for(int i = 0; i < H+4; i++)
            gameBoard[i][0] = gameBoard[i][1] = gameBoard[i][W+2] = gameBoard[i][W+3] = '#';
        for(int i = 0; i < W+4; i++)
            gameBoard[0][i] = gameBoard[1][i] = gameBoard[H+2][i] = gameBoard[H+3][i] = '#';

        cout<<solve()<<"\n";
        showGameBoard();
    }
}