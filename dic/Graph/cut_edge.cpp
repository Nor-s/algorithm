#include <set>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

int V, E;
vector<vector<int>> adjList;
set<pair<int, int>> answer;

int dfs(int here, int parent, vector<int> &discovered, int &visitedNum)
{ // 단절선을 제거했을때 -> connected component의 개수가 증가
    int ret = discovered[here] = visitedNum++;

    for (int i = 0; i < adjList[here].size(); i++)
    {
        int there = adjList[here][i];
        int subTree = discovered[there];
        if (parent == there) // 부모노드로 가는간선 제외해야함
            continue;        // 무시안할시 항상 부모노드와 같거나 작은값가지게됨
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
                answer.insert({a, b}); // 단절선을 모두 구함.
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
    cout << answer.size() << "\n"; // 단절선의 개수
    for (auto item : answer)
    {
        cout << item.first << " " << item.second << "\n"; // 단절선을 사전순으로 한 줄에 하나씩 출력
    }
}