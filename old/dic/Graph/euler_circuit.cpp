#include <vector>

using namespace std;

vector<vector<int>> adj;

void getEulerCircuit(int here, vector<int> &circuit)
{ // 모든 정점들이 짝수점이어야함
    for (int there = 0; there < adj.size(); ++there)
    {
        while (adj[here][there] > 0)
        {
            adj[here][there]--;
            adj[there][here]--;
            getEulerCircuit(there, circuit);
        }
    }
    circuit.push_back(here); // 역순으로 추가되는 것이라서 결과적으로 나오는 서킷을 뒤집어야한다 (무향 그래프는 필요없다.)
}