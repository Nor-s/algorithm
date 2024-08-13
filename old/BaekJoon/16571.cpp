#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_ 3

using namespace std;

int board[MAX_][MAX_];
int turn = 0;
// w = 1, l = -1, d = 0

bool is_end()
{
    for (int i = 0; i < MAX_; i++)
    {
        int count = 0;
        for (int j = 1; j < MAX_; j++)
        {
            if (board[i][j] != 0 && board[i][j] == board[i][j - 1])
            {
                count++;
            }
        }
        if (count == MAX_ - 1)
        {
            return true;
        }
    }
    for (int i = 0; i < MAX_; i++)
    {
        int count = 0;
        for (int j = 1; j < MAX_; j++)
        {
            if (board[j][i] != 0 && board[j][i] == board[j - 1][i])
            {
                count++;
            }
        }
        if (count == MAX_ - 1)
        {
            return true;
        }
    }
    int count = 0;
    for (int i = 1; i < MAX_; i++)
    {
        if (board[i][i] != 0 && board[i][i] == board[i - 1][i - 1])
        {
            count++;
        }
    }
    if (count == MAX_ - 1)
    {
        return true;
    }

    count = 0;
    for (int i = 1; i < MAX_; i++)
    {
        if (board[i][MAX_ - 1 - i] != 0 && board[i][MAX_ - 1 - i] == board[i - 1][MAX_ - i])
        {
            count++;
        }
    }
    if (count == MAX_ - 1)
    {
        return true;
    }

    return false;
}

int bestResult()
{
    int current = (turn % 2 == 0) ? 1 : 2;
    int ret = -3;
    bool is_updated = false;

    for (int i = 0; i < MAX_; i++)
    {
        for (int j = 0; j < MAX_; j++)
        {
            if (board[i][j] != 0)
            {
                continue;
            }
            else
            {
                is_updated = true;
                board[i][j] = current;
                if (is_end())
                {
                    board[i][j] = 0;
                    return 1;
                }
                else
                {
                    turn++;
                    ret = max(ret, -bestResult());
                    turn--;
                    board[i][j] = 0;
                }
            }
        }
    }
    if (!is_updated)
    {
        return 0;
    }
    else
    {
        return ret;
    }
}

void solve()
{
    int result = bestResult();
    if (result == 1)
    {
        cout << "W\n";
    }
    else if (result == 0)
    {
        cout << "D\n";
    }
    else
    {
        cout << "L\n";
    }
}

int main()
{
    for (int i = 0; i < MAX_; i++)
    {
        for (int j = 0; j < MAX_; j++)
        {
            cin >> board[i][j];
            if (board[i][j] != 0)
            {
                turn++;
            }
        }
    }
    solve();
}