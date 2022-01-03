#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <iomanip>
 
using namespace std;


int C;
int N, M;
 
vector<vector<pair<double, int> > > circuit;
 
double dijkstra()
{
    vector<double> ret(N, 5.0/0.0);
    priority_queue<pair<double, int> , vector<pair<double, int> >, greater<pair<double, int> > > pq;
    ret[0] = 1.0;
    pq.push(make_pair(1.0, 0));
    while(!pq.empty())
    {
        int here = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
cout<<"-----pop----"<<cost<<"\n";
 
        if(ret[here] < cost) continue;
 
        for(int i = 0; i < circuit[here].size(); i++)
        {
            int there = circuit[here][i].second;
            double nextDist = cost * circuit[here][i].first;
cout<<"there: "<<there<<" here: "<< here<<" nextDist: "<<nextDist<<" ret[there]: "<<ret[there]<< " cost: "<<cost<<" circuit.first: "<<circuit[here][i].first<<"\n";
            if(nextDist  < ret[there] )
            {
cout<<"----push---"<<nextDist <<"\n";
                ret[there] = nextDist;
                pq.push(pair<double, int>(nextDist, there));
            }
        }
    }
    return ret[N-1];
}


int main()
{
    cin>>C;
    while(C--)
    {
 
        cin>>N>>M;
        circuit = vector<vector<pair<double, int> > >(N);
        for(int i = 0; i < M; i++)
        {
            int a, b;
            double c;
            cin>>a>>b>>c;
            circuit[a].push_back(make_pair(c, b));
            circuit[b].push_back(make_pair(c, a));
        }
        cout<<dijkstra()<<"\n";
     //   cout<<fixed<<setprecision(10);
 
    }
}