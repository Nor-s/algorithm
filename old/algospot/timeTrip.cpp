#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
using namespace std;

int G, W;
vector<vector<pair<int, int> > > adj;
vector<int> D;
vector<vector<bool> > reachable;

void reachableInitialize()
{
  reachable = vector<vector<bool> > (G, vector<bool>(G, false));
  
  for(int i = 0; i < G; i++)
	for(int j = 0; j < adj[i].size(); j++)
	  reachable[i][adj[i][j].second] = true;
  
  for(int k = 0; k < G; k++)
  {
	for(int here = 0; here < G; here++)
	{
	  	for(int there = 0; there < G; there++)
		{
		  if(reachable[here][k]&&reachable[k][there])
			reachable[here][there] = true;
		}
	}
  }
}

bool bellman()
{
    D = vector<int>(G, INFINITY);
    int updated = false;
  	D[0] = 0;
    for(int i = 0; i < G; i++)
        for(int here = 0; here < G; here++)
        {
            for(int k = 0; k < adj[here].size(); k++)
            {
                int cost = adj[here][k].first;
                int there = adj[here][k].second;

                if(D[there] > D[here] + cost)
                {
                    if(i == G-1  && reachable[0][here] && reachable[here][1])
                        updated = true;
                    
//cout<<"there: "<<there <<" here : "<< here << " cost: "<< cost<<" dhere " << D[here] <<" dthere "<<D[there]<<"\n";
                    D[there] = D[here] + cost; 
//    cout<<"----D[there]: "<<D[there]<<"\n";
                }
            }
        }
  	return updated;
}

int main()
{
    int C;
    cin>>C;
    while(C--)
    {
        cin>>G;
        cin>>W;
        adj = vector<vector<pair<int, int> > >(G, vector<pair<int , int> >());
        for(int i = 0; i < W; i++)
        {
            int a, b, d;
            cin>>a>>b>>d;
            adj[a].push_back(make_pair(d, b));
        }
	    reachableInitialize();
	    if(!reachable[0][1]) 	 
		{
		  cout<<"UNREACHABLE\n";
          continue;
        }
	  
        if(bellman())
            cout<<"INFINITY";
        else
            cout<<D[1];
        cout<<" ";
	  
	    for(int i = 0; i < G; i++)
		  	for(int j = 0; j < adj[i].size(); j++)
			  	adj[i][j] = make_pair(-adj[i][j].first, adj[i][j].second);
	     
	    if(bellman())
            cout<<"INFINITY";
        else
            cout<<-D[1];
        cout<<"\n";
	  
    }
}