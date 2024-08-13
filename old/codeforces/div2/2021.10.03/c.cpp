#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#define COUT(a) cout << a << "\n"
#define CCOUT(a, b) cout << a << b << "\n"
#define CCCOUT(a, b, c) cout << a << b << c << "\n"

using namespace std;

vector<int> A;
vector<vector<int>> adjList;
vector<int> discovered;
int num = 0;
// 1 ~ k-1 개의 선을 잘라내야함.

int dfs(int here, int parent, vector<int> &discovered, int &visitedNum)
{
    int ret = discovered[here] = visitedNum++;

    for (int i = 0; i < adjList[here].size(); i++)
    {
        int there = adjList[here][i];
        int subTree = discovered[there];
        if (parent == there)
            continue;
        if (subTree == -1)
        {
            subTree = dfs(there, here, discovered, visitedNum);
            if (subTree > discovered[here])
            {
                int a = here, b = there;
                if (a > b)
                {
                    swap(a, b);
                }
                answer.insert({a, b});
            }
        }
        ret = min(ret, subTree);
    }
    return ret;
}

void dfsAll()
{
    vector<int> discovered(V + 1, -1);
    int visitedNum = 0;
    for (int i = 0; i < V; i++)
    {
        if (discovered[i + 1] == -1)
        {
            dfs(i + 1, 0, discovered, visitedNum);
        }
    }
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
        int n, k;
        cin >> n >> k;
        A.resize(n);
        num = 0;
        discovered.clear();
        discovered.resize(n, -1);
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
        adjList.clear();
        adjList.resize(n);
        for (int i = 0; i < n - 1; i++)
        {
            int a, b;
            cin >> a >> b;
            adjList[a].push_back(b);
            adjList[b].push_back(a);
        }
    }
}