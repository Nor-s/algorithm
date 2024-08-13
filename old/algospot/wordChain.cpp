#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int n;
string words[100];
vector<vector<int> > graph;
vector<vector<vector<int> > > dic;
int odd[26];
bool makeGraph()
{
    odd[1] = -1;
    graph = vector<vector<int> >(26, vector<int>(26, 0));
    dic = vector<vector<vector<int> > >(26, vector<vector<int> >(26));
    int count[26] = {0, };
    for(int i = 0; i < n; i++)
    {
        int a = words[i][0] - 'a';
        int b = words[i].back() - 'a';

        graph[a][b]++;
        dic[a][b].push_back(i);

        count[a]++;
        count[b]++;
    }
    int k = 0;
    for(int i = 0; i < 26; i++)
    {
        if(count[i]%2 != 0) {
            odd[k++] = i;
        }
    }
    if(!(k == 0||k == 2)) return false;

    return true;
}

void dfs(int here, vector<int>& circuit)
{
    for(int next = 0; next < 26; next++) {
        while(graph[here][next] > 0)
        {
            graph[here][next]--;
            graph[next][here]--;
            dfs(next, circuit);
        }
    }
    circuit.push_back(here);
}

bool dfsAll(vector<int>& circuit) {
    for(int i = 0, k = 0; i < 26; i++) {
        for(int j = 0; j < 26; j++) {
            if(graph[i][j] > 0) {
                if(k++ > 1) return false;
                dfs(i, circuit);
            }
        }
    }
    return true;
}


bool etrail() {
    vector<int> circuit;
    vector<vector<int> > tmp(graph);

    if(odd[1] != -1) {

    }
    else if(!dfsAll(circuit)) return false;

    
    reverse(circuit.begin(), circuit.end());
    for(int i = 0; i < circuit.size(); i++)
        cout<<(char)(circuit[i] + 'a')<<" ";
    cout<<"\n";
    return true;
}

int main() {
    int C;
    cin>>C;
    while (C--)
    {
        cin>>n;
        for(int i = 0; i < n; i++)
            cin>>words[i];
        if(!makeGraph() || !etrail()){
            cout<<"IMPOSSIBLE\n";
            continue;
        }
    }
}