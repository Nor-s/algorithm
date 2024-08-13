#include <set>
#include <vector>
#include <set>
#include <iostream>

using namespace std;
// 절단점을 포함하지 않는 서브그래프 == 이중결합 컴포넌트
int V, E;
vector<vector<int>> adjList;
set<int> answer;

int dfs(int here, vector<int> &visited, int &visitedNum, bool isRoot)
{
    visited[here] = ++visitedNum;
    int ret = visited[here], child = 0;

    for (int i = 0; i < adjList[here].size(); i++)
    {
        int there = adjList[here][i];
        if (visited[there] == -1)
        {
            child++;
            int subtree = dfs(there, visited, visitedNum, false);
            if (!isRoot && subtree >= visited[here])
            {
                answer.insert(here); // 절단점!
            }
            ret = min(ret, subtree);
        }
        else
        {
            ret = min(ret, visited[there]);
        }
    }
    if (isRoot && child > 1)
    {
        answer.insert(here); // 루트 -> 자손노드가 두개이상이면 루트삭제시 무조건 두개의 컴포넌트
    }
    return ret;
}

void dfsAll()
{
    vector<int> visited(V + 1, -1);
    int visitedNum = 0;
    for (int i = 0; i < V; i++)
    {
        if (visited[i + 1] != -1)
            continue;
        dfs(i + 1, visited, visitedNum, true);
    }
    cout << answer.size() << "\n"; // 단절점의 개수
    for (auto item : answer)
    {
        cout << item << " "; // 단절점의 번호, 오름차순
    }
}