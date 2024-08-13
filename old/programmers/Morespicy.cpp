#include <string>
#include <vector>
#include <queue>
using namespace std;
int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int> pq;
    
    for(int i = 0; i < scoville.size(); i++)
        pq.push(-scoville[i]);
    while(pq.size() != 1)
    {
        int small1 = -pq.top(); pq.pop();
        int small2 = -pq.top(); pq.pop();
        if(small1 >= K)
            break;
        pq.push(-(small1 + (small2*2)));
        answer++;
    }
    if(-pq.top() < K)
        answer = -1;
    
    return answer;
}