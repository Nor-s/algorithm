#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <iomanip>

using namespace std;
int N;
vector<vector<int> > gameBoard;
vector<vector<bool> > adj;
vector<vector<pair<int, int> > > mem;
vector<vector<int> > groupA;
vector<vector<int> > groupB;
vector<bool> visited;
vector<int> matchA, matchB;

int an, bn;

bool dfs(int a)
{
    if(visited[a]) return false;
    visited[a] = true;
    for(int b = 0; b < bn; b++)
    {
        if(adj[a][b])
            if(matchB[b] == -1 || dfs(matchB[b]))
            {
                matchA[a] = b;
                matchB[b] = a;
                return true;
            }
    }

    return false;
}

int solve()
{
    int ret = 0;
    matchA = vector<int>(an, -1);
    matchB = vector<int>(bn, -1);
    for(int i = 0; i < an; i++)
    {
        visited = vector<bool>(an, false);
        if(dfs(i))
            ret++;
    }
    return ret;
}

int main()
{
    int C;
    cin>>C;
    while(C--)
    {
        cin>>N;
        gameBoard = vector<vector<int> > (N+2, vector<int>(N+2));
        groupA = vector<vector<int> > (N+2, vector<int>(N+2, -1));
        groupB = vector<vector<int> > (N+2, vector<int>(N+2, -1));
        an = bn = 0;
        getchar();
        for(int i = 1; i < N+1; i++)
            for(int j = 1; j < N+1; j++)
            {
                char ch;
                cin>>ch;
                gameBoard[i][j] = (int)ch;
            }
        for(int i = 0; i < N+2; i++)
        {
            gameBoard[0][i] = gameBoard[N+1][i] = (int)'*';
            gameBoard[i][0] = gameBoard[i][N+1] = (int)'*';
        }

        for(int i = 1; i < N + 1; i++)
            for(int j = 1; j < N + 1; j++)
            {
                if(gameBoard[i][j] == '*') 
                {
                    groupA[i][j] = groupB[i][j] = -1;
                    continue;
                }
                if(gameBoard[i-1][j-1] == '*')
                    groupA[i][j] = an++;
                else
                    groupA[i][j] = groupA[i-1][j-1];

                if(gameBoard[i-1][j+1] == '*')
                    groupB[i][j] = bn++;
                else   
                    groupB[i][j] = groupB[i-1][j+1];
            }
        adj = vector<vector<bool> > (an, vector<bool>(bn, false));

        for(int i = 1; i < N + 1; i++)
            for(int j = 1; j < N + 1; j++)
                if(groupA[i][j] != -1 && groupB[i][j] != -1)
                    adj[groupA[i][j]][groupB[i][j]] = true;
 /*
        cout<<setprecision(3);
        for(int i = 0; i < N + 2; i++)
        {
            for(int j = 0; j < N + 2; j++)
                cout<<(char)gameBoard[i][j]<<" ";
            cout<<"\n";
        }               
        for(int i = 1; i < N + 1; i++)
        {
            for(int j = 1; j < N + 1; j++)
                cout<<groupA[i][j]<<" ";
            cout<<"\n";
        }               
  
        for(int i = 1; i < N + 1; i++)
        {
            for(int j = 1; j < N + 1; j++)
                cout<<groupB[i][j]<<" ";
            cout<<"\n";
        }              
        */

        cout<<solve()<<"\n";
    }
}