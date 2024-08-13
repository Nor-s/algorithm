#include <bits/stdc++.h>

using namespace std;

bool pop(map<int, int> &mm, int x)
{
    mm[x]--;
    if (mm[x] == 0)
    {
        mm.erase(x);
        return true;
    }
    return false;
}
bool push(map<int, int> &mm, int x)
{
    mm[x]++;
    if (mm[x] == 1)
    {
        return true;
    }
    return false;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n, k;
    vector<int> board;
    map<int, int> two;
    map<int, int> one;
    cin >> n >> k;
    board.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> board[i];
        push(one, board[i]);
    }
    int answer = INT32_MAX;
    int i = 0, j = -1;
    while (i != n)
    {
        pop(one, board[i]);
        push(two, board[i]);
        while (one.size() == k && two.size() == k && j < i)
        {
            answer = min(answer, i - j);
            j++;
            pop(two, board[j]);
            push(one, board[j]);
        }
        while (one.size() != k && j < i)
        {
            j++;
            pop(two, board[j]);
            push(one, board[j]);
        }
        i++;
    }
    if (answer == INT32_MAX)
    {
        answer = 0;
    }
    cout << answer;
}