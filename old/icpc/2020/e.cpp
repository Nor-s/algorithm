#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int m;
//점의 개수를 나타내는 정수 3 ≤ n ≤ 500,000 과 진행된 차례의 수를 나타내는 정수 3 ≤ m ≤ 1,000,000
// 유니온 파인드

struct uf
{
    vector<int> parent;
    vector<int> rank;
    uf(const int &n) : rank(n, 1)
    {
        for (int i = 0; i < n; i++)
        {
            parent.push_back(i);
        }
    }
    int find(const int &u)
    {
        int ret = u;
        while (parent[ret] != ret)
        {
            int v = parent[ret];
            parent[ret] = parent[v];
            ret = v;
        }
        return ret;
    }
    int merge(int &u, int &v)
    {
        u = find(u), v = find(v);
        if (u == v)
            return 2;
        if (rank[u] > rank[v])
            swap(u, v);
        parent[u] = v;
        if (rank[u] == rank[v])
            rank[v]++;
        return 1;
    }
};

int main()
{
    cin >> n >> m;
    uf uff(n);
    int stage = 0;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        int tmp = uff.merge(a, b);
        if (stage == 0 && tmp == 2)
        {
            stage = i + 1;
        }
    }
    cout << stage;
}