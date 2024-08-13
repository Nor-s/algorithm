#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <iomanip>

using namespace std;

struct SET{
    vector<int> father, rank;
    SET(int V) : father(V, 0) , rank(V, 1)
    {
        for(int i = 0; i < V; i++)
            father[i] = i;
    }
    int find(int u)
    {
        if(father[u] == u) return u;
        return father[u] = find(father[u]);
    }
    void merge(int u, int v)
    {
        u = find(u); v = find(v);
        if(u == v) return;
        if(rank[u] > rank[v]) swap(u, v);
        father[u] = v;
        if(rank[u] == rank[v]) rank[v]++;
    }

};

const double INF = 3000.0;

int C;
int N;
int M;
vector<int> X, Y;

vector<vector<double> > adj;

double sqr(double x)
{
    return x*x;
}
double dist(int a, int b)
{
    return sqrt(sqr(Y[a] - Y[b]) + sqr(X[a] - X[b]));
}

double kruskal()
{
    double ret = 0;
    SET ufs(N);
    vector<pair<double, pair<int, int> > > order;
    for(int i = 0; i < N; i++)
        for(int j = i+1; j < N; j++)
            if(adj[i][j] != INF) order.push_back(make_pair(adj[i][j], make_pair(i, j)));
    sort(order.begin(), order.end());
    for(int i = 0; i < order.size(); i++)
    {
        int u = order[i].second.first;
        int v = order[i].second.second;
        double cost = order[i].first;
        if(ufs.find(u) == ufs.find(v)) continue;
        ufs.merge(u, v);
        ret+=cost;
    }
    return ret;
}

int main()
{
    int a1 = 0, b1 = 0;
    cout<<fixed<<setprecision(10)
    cin>>C;
    while(C--)
    {
        cin>>N>>M;
        adj = vector<vector<double> > (N, vector<double>(N, INF) );
        X = vector<int>(N,0);
        Y = vector<int>(N, 0);
        for(int i = 0; i < N; i++) cin>>X[i];
        for(int i = 0; i < N; i++) cin>>Y[i];

        for(int i = 0; i < M; i++)
        {
            cin>>a1>>b1;
            adj[a1][b1] = 0.;
            adj[b1][a1] = 0.;
        }
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                if(adj[i][j] == INF && i != j)
                    adj[i][j] = adj[j][i] = dist(i, j);

        cout<<kruskal()<<"\n";
    }
}