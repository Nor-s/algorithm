#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

vector<vector< int> > adj;
vector<int> discovered;
vector<int> sccId;
stack<int> st;

int counter,counterSCC;

int scc(int here)
{
    int ret = discovered[here] = counter++;
    st.push(here);
    for(int i = 0 ; i < adj[here].size(); i++)
    {
        int there = adj[here][i];
        if(discovered[there] == -1)
            ret = min(ret, scc(there));
        else if(sccId[there]== -1)
            ret = min(ret, discovered[there]);
    }
    
    if(discovered[here] == ret)
    {
        while(true)
        {
            int t = st.top();
            sccId[t] = counterSCC;
            st.pop();
            if(t == here) break;
        }
        counterSCC++;
    }
    return ret;
}
vector<int> sccAll()
{
    discovered = sccId = vector<int>(adj.size(), -1);
    counter = counterSCC = 0;
    for(int i = 0; i < adj.size(); i++) if(!discovered[i])scc(i);
    return sccId;
}