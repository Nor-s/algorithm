#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int w, h;
vector<vector<int>> board;
vector<vector<int>> psum;

void init()
{
    psum.clear();
    psum.resize(h, vector<int>(w, 0));
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            int a = 0;
            int b = 0;
            int c = 0;
            if (i - 1 >= 0 && j - 1 >= 0)
            {
                c = psum[i - 1][j - 1];
            }
            if (i - 1 >= 0)
            {
                a = psum[i - 1][j];
            }
            if (j - 1 >= 0)
            {
                b = psum[i][j - 1];
            }
            psum[i][j] = a + b - c + board[i][j];
            //    cout << psum[i][j] << " ";
        }
        // cout << "\n";
    }
    // cout << "\n";
}

int bf()
{
    int answer = 0;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            for (int k = i; k < h; k++)
            {
                for (int p = j; p < w; p++)
                {
                    int a = 0;
                    int b = 0;
                    int c = 0;
                    if (i - 1 >= 0 && j - 1 >= 0)
                    {
                        c = psum[i - 1][j - 1];
                    }
                    if (i - 1 >= 0)
                    {
                        a = psum[i - 1][p];
                    }
                    if (j - 1 >= 0)
                    {
                        b = psum[k][j - 1];
                    }
                    int sum = psum[k][p] - a - b + c;
                    if (sum == 10)
                    {
                        answer++;
                    }
                    if (sum > 10)
                    {
                        break;
                    }
                }
            }
        }
    }
    return answer;
}

int main()
{
    cin >> h >> w;
    board.resize(h, vector<int>(w));
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> board[i][j];
        }
    }
    init();
    cout << bf();
}