#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

vector<vector<int> > adj;
vector<vector<int> > delayNum;
vector<int> delay;
int V, E;

void floyd()
{
    for(int i = 1; i < V+1; i++)
        adj[i][i] = 0;

    for(int k = 1; k < V+1; k++)
        for(int here = 1; here < V+1; here++)
                for(int there = 1; there < V+1; there++)
                {
                    int a = delayNum[here][k];
                    int b = delayNum[k][there];
                    int delayA = delay[a];
                    int delayB = delay[b];
                    int A = adj[here][k] - delayA;
                    int B = adj[k][there] - delayB;

                    if( adj[here][there] > A + B + max(max(delayA, delayB), delay[k]))
                    {
                        delayNum[here][there] = delayA > delayB ? a : b;
                        delayNum[here][there] = delay[delayNum[here][there]] > delay[k] ? delayNum[here][there] : k;
                        
                        adj[here][there] = A + B + max(max(delayA, delayB), delay[k]);
                    }
                }
}
int main()
{
    int T;
    cin>>V>>E;
    adj = vector<vector<int> > (V+1, vector<int>(V+1, 1000000));
    delayNum = vector<vector<int> > (V+1, vector<int>(V+1, 0));
    delay = vector<int> (V+1, 0);
    for(int i = 1; i < V+1; i++)
        cin>>delay[i];
    for(int j = 0; j < E; j++)
    {
        int a, b, c;
        cin>>a>>b>>c;
        adj[b][a] = c;
        adj[a][b] = c;
    }
    floyd();
    
    cin>>T;
    while(T--)
    {
        int a, b;
        cin>>a>>b;
        cout<<adj[a][b]<<"\n";
    }
}