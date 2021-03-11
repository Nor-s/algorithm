#include <string>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
//: min_heap  
int solution(vector<vector<int>> jobs) {
    int time = 0, sum = 0, i = 0;
    sort(jobs.begin(), jobs.end());
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, 0));
    while(!pq.empty())
    {
        int spend = -pq.top().first, start = pq.top().second;
        pq.pop();
        sum += time - start + spend;
        time += spend;
        while(i < jobs.size() && time >= jobs[i][0])
        {
            pq.push(make_pair(-jobs[i][1], jobs[i][0]));
            i++;
        }
        if(pq.empty() && i < jobs.size())
        {
            time = jobs[i][0];
            pq.push(make_pair(-jobs[i][1], jobs[i][0]));
            i++;
        }
    }
    return sum/jobs.size();
}