#include <iostream>

using namespace std;

int top[4][9];
int K;

void rotateOne(int num, int dir)
{
    top[num][8] = (top[num][8] + 8 - dir) % 8;
}
int getNumber(int num, bool bIsLeft)
{
    int numIdx = (2 + top[num][8]) % 8;
    if (bIsLeft)
    {
        numIdx = (6 + top[num][8]) % 8;
    }
    return top[num][numIdx];
}
void rotate(int num, int dir)
{
    int left = getNumber(num, true);
    int right = getNumber(num, false);
    int dirs[4] = {
        0,
    };
    dirs[num] = dir;
    for (int i = num - 1; i > -1; i--)
    {
        int leftNext = getNumber(i, true);
        int rightNext = getNumber(i, false);
        if (rightNext == left)
        {
            break;
        }
        left = leftNext;
        right = rightNext;
        dirs[i] = dirs[i + 1] * -1;
    }

    left = getNumber(num, true);
    right = getNumber(num, false);
    for (int i = num + 1; i < 4; i++)
    {
        int leftNext = getNumber(i, true);
        int rightNext = getNumber(i, false);
        if (leftNext == right)
        {
            break;
        }
        left = leftNext;
        right = rightNext;
        dirs[i] = dirs[i - 1] * -1;
    }
    for (int i = 0; i < 4; i++)
    {
        rotateOne(i, dirs[i]);
    }
}

int eval()
{
    int sum = 0;
    (top[0][top[0][8]]) ? (sum += 1) : (sum += 0);
    (top[1][top[1][8]]) ? (sum += 2) : (sum += 0);
    (top[2][top[2][8]]) ? (sum += 4) : (sum += 0);
    (top[3][top[3][8]]) ? (sum += 8) : (sum += 0);
    return sum;
}

int main()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            char ch;
            cin >> ch;
            top[i][j] = (int)ch - '0';
        }
    }

    cin >> K;
    for (int i = 0; i < K; i++)
    {
        int num, dir;
        cin >> num >> dir;
        num--;
        rotate(num, dir);
    }
    cout << eval();
}
