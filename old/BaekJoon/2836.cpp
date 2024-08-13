#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int N, M;
// end start
vector<pair<long long, long long> > dpp;

long long answer = 0;
// m = house, N = people.
void solve() {
    priority_queue<pair<long long, long long> > pq;
    long long current = 0;

    dpp.push_back({M + 1, M + 1});
//std::cout<<"-------\n";
    for (int i = 0; i < dpp.size(); i++) {
        long long startPoint = INT64_MIN;
        long long uturnPoint = INT32_MAX;
        long long endPoint = INT64_MIN;

        // start < end 
        while(!pq.empty() && pq.top().first < dpp[i].first) {
            startPoint = max(pq.top().first, startPoint);
            endPoint = max(pq.top().second, endPoint);
            uturnPoint = min(pq.top().second, uturnPoint);

            pq.pop();
        }
        if(startPoint != INT64_MIN) {
     //       cout<<"--------"<<i<<"\n";
            if(startPoint <= current) {
                current = endPoint;
            }
            else if(uturnPoint < startPoint) {
                answer += (startPoint - current);
                current = startPoint;
                answer += (current - uturnPoint);
                current = uturnPoint;
                answer += (endPoint - current);
                current = endPoint;
            }
            else {
                answer += (endPoint - current);
                current = endPoint;
            }
        }
        // start end
        pq.push({dpp[i].second, dpp[i].first});
   //     cout<<dpp[i].first<<" "<<dpp[i].second<<"   answer: "<<answer<<"\n";
    }
    cout<<answer + (M-current)<<"\n";
}

int main() {
    cin>>N>>M;
    // a -> b  // b < - a
    for (int i = 0; i < N; i++) {
        long long a, b;
        cin>>a>>b;
        dpp.push_back({b, a});
    }

    sort(dpp.begin(), dpp.end());
    solve();
}