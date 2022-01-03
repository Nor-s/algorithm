#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

const int INF = 987654321;

int n, m, v, asum = 0, bsum = 0;
int a[50] = {0,};
int b[50] = {0,};
int graph[102][102] = {0,};
int flow[102][102] = {0,};

void initialize()
{
    v = n + m + 2;
    for(int i = 0; i < n; i++)
        graph[0][i + 2] = a[i];
    for(int i = 0; i < m; i++)
        graph[n + 2 + i][1] = b[i];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            graph[i+2][j+n+2] = 1;
}
int networkFlow(int src, int sink)
{ 
    int ret = 0;

    while(true)
    {
        queue<int> q;
        q.push(src);
        vector<int> parent = vector<int> (v, -1);
        parent[src] = src;

        while(!q.empty()&&parent[sink] == -1)
        {
            int here = q.front(); q.pop();
            for(int i = 0; i < v; i++)
            {
                if(parent[i] == -1 && graph[here][i]- flow[here][i] > 0)
                {
                    q.push(i);
                    parent[i] = here;
                    if(i == sink) break;
                }
            }
        }
        if(parent[sink] == -1) break;

        for(int p = sink; p != src; p = parent[p])
        {
            flow[parent[p]][p]++; 
            flow[p][parent[p]]--;
        }
        ret++;
    }
    return ret;
}

bool searchSwap(int s, int e)
{
    for(int j = 2 + n + m; j > e; j--)
    {
        for(int i = s+1; i < 2 + n; i++)
        {
            if(flow[i][j] > 0&& !(flow[s][j] > 0) && !(flow[i][e] > 0))
            {
                flow[s][e] = 0;
                flow[s][j] = 1;
                flow[i][j] = 0;
                flow[i][e] = 1;
                return true;
            }
        }
    }
    return false;
}

void matching()
{
    for(int i = 2; i < 2 + n; i++)
    {
        for(int j = 2+n; j < 2 + n + m; j++)
            if(flow[i][j] > 0)
            {
                if(searchSwap(i, j))
                    cout<<0;
                else    
                    cout<<1;
            }
            else
                cout<<0;
        cout<<"\n";
    }
}

void solve()
{
    int ret = networkFlow(0, 1);
    if(ret != bsum)
    {
        cout<<-1<<"\n"; 
        return;
    }
    matching();
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
        asum+= a[i];
    }
    for(int j = 0; j < m; j++)
    {
        cin>>b[j];
        bsum+= b[j];
    }
    if(asum != bsum)
    {
        cout<<-1<<"\n";
        return 0;
    }
    initialize();
    solve();
}