// s:
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <cmath>

using namespace std;

std::vector<int> tree;
int twin_result = 0;
int D, N, U, T;
std::vector<bool> isBreakEdge;
bool bPonyIsGoal = false;
int visitCount = 0;

int calcDepth(int node)
{
    int depth = 1;
    while (node > 1)
    {
        node /= 2;
        depth++;
    }
    return depth;
}

void dfs(int node, int twin, int TT = 0)
{
    tree[node] = 1;
    twin_result = max(twin_result, twin);
    int left = node * 2;
    int right = node * 2 + 1;
    bool bIsLeftOkay = false;
    bool bIsRightOkay = false;
    twin += U;

    if (left <= tree.size() - 1)
    {
        bIsLeftOkay = !isBreakEdge[left];
    }
    if (right <= tree.size() - 1)
    {
        bIsRightOkay = !isBreakEdge[right];
    }
    if (bIsLeftOkay && bIsRightOkay)
    {
        TT += T;
        twin += TT;
    }
    if (bIsLeftOkay)
    {
        dfs(left, twin, TT);
    }
    if (bIsRightOkay)
    {
        dfs(right, twin, TT);
    }
}

int main()
{
    std::vector<pair<int, int>> v;
    cin >> D >> N >> U >> T;

    tree.resize(pow(2, D), 0);
    isBreakEdge.resize(pow(2, D), false);

    int s, e;
    for (int i = 0; i < N; i++)
    {
        cin >> s >> e;
        isBreakEdge[e] = true;
    }
    dfs(1, 0);
    int goal = 0;
    int nodeCount = 0;
    for (int i = tree.size() - 1; i > 0; i--)
    {
        if (goal == 0 && tree[i] == 1)
        {
            goal = i;
        }
        if (tree[i] == 1)
        {
            nodeCount++;
        }
    }
    int goaldepth = calcDepth(goal) - 1;
    int ponyresult = ((nodeCount - 1) * 2 - goaldepth) * U;
    if (ponyresult < twin_result)
    {
        cout << ":blob_twintail_sad:";
    }
    else if (ponyresult == twin_result)
    {
        cout << ":blob_twintail_thinking:";
    }
    else
    {
        cout << ":blob_twintail_aww:";
    }
}