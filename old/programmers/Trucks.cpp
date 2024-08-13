#include <string>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0, capa = 0, move = 0;
    queue<pair<int, int> > q;
    truck_weights.push_back(weight);
 
    for(int i = 0; i < truck_weights.size(); i++)
    {
        bool isMove = false;
        while(capa + truck_weights[i] > weight )
        { 
            capa -= q.front().second;    
            move = bridge_length - (answer - q.front().first);
            answer += move;
            q.pop();
            isMove = true;
        }
        if((!q.empty())&&(1 == bridge_length - (answer - q.front().first)))
        { 
            capa -= q.front().second;
            q.pop();
        }
        if(!isMove) answer++;
        capa += truck_weights[i];
        q.push(make_pair(answer, truck_weights[i]));
    }
    
    return answer;
}