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
    	int totalMove =0;
        while(capa + truck_weights[i] > weight )
        {
            int thisPos = q.front().first;
            int frontWeight = q.front().second;
            q.pop();
            capa -= frontWeight;
            	
            move = bridge_length - (answer - thisPos);
            totalMove += move;
            answer += move;
        }
        if((!q.empty())&&(1 == bridge_length - (answer - q.front().first)))
        {
            capa -= q.front().second;
            q.pop();
        }
        if(i == truck_weights.size()-1) break;
        if(totalMove == 0) answer++;
        capa += truck_weights[i];
        q.push(make_pair(answer, truck_weights[i]));
    }
    
    return answer;
}