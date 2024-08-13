#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

set<int> bracketIdx;
// 0 1 2 3 4 5
//  0 1 2 3 4
vector<int> num;
vector<char> op;

int expression(int a, char op, int b)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '*':
        return a * b;
    }
    return a - b;
}

int calc()
{
    vector<char> newOp;
    vector<int> newInt;
    newInt.push_back(num[0]);
    for (int i = 0; i < op.size(); i++)
    {
        if (auto it = bracketIdx.find(i); it != bracketIdx.end())
        {
            int tmp = expression(num[i], op[i], num[i + 1]);
            newInt.pop_back();
            newInt.push_back(tmp);
        }
        else
        {
            newInt.push_back(num[i + 1]);
            newOp.push_back(op[i]);
        }
    }
    for (int i = 0; i < newOp.size(); i++)
    {
        int tmp = expression(newInt[i], newOp[i], newInt[i + 1]);
        newInt[i + 1] = tmp;
    }
    return newInt.back();
}

int answer = INT32_MIN;

void subset(int idx)
{
    if (idx > op.size())
    {
        answer = max(answer, calc());
        return;
    }
    bracketIdx.insert(idx);
    subset(idx + 2);
    bracketIdx.erase(idx);
    subset(idx + 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    {
        cin >> N;
    }

    vector<char> vc(N);
    {
        for (int i = 0; i < N; i++)
        {
            cin >> vc[i];
            if ('0' <= vc[i] && vc[i] <= '9')
            {
                num.push_back(vc[i] - '0');
            }
            else
            {
                op.push_back(vc[i]);
            }
        }
    }
    subset(0);
    cout << answer;
}