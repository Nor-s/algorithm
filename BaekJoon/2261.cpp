#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>

using namespace std;
int n;
vector<pair<int, int> > xy;


int dist(const pair<int, int>& a, const pair<int, int>& b) {
    return (a.first-b.first)*(a.first-b.first) + (a.second - b.second)*(a.second - b.second);
}

int sol() {
    set<pair<int, int> > s;
    int minDist = dist(xy[0], xy[1]), idx = 0;
    s.insert( {xy[0].second, xy[0].first} );
    s.insert( {xy[1].second, xy[1].first} );

    for(int i = 2; i < xy.size(); i++) {
        while(idx < i) {
            int tmp = xy[i].first - xy[idx].first;
            if(tmp*tmp < minDist) {
                break;
            }
            else {
                s.erase({xy[idx].second, xy[idx].first});
                idx++;
            }
        }
        auto start = s.lower_bound(make_pair(xy[i].second - sqrt(minDist), INT32_MIN));
        auto end = s.upper_bound(make_pair(xy[i].second + sqrt(minDist),  INT32_MAX));
        for(auto it = start; it != end; it++) {
            minDist = min(minDist, dist(xy[i], {it->second, it->first}));
        }

        s.insert({xy[i].second, xy[i].first});
    }

    return minDist;
}

int main() {
    cin>>n;
    xy = vector<pair<int, int> >(n);
    
    for(int i = 0; i < n; i++) {
        int a, b;
        cin>>a>>b;
        xy[i].first = a;
        xy[i].second = b;
    }
    sort(xy.begin(), xy.end());
    cout<<sol();
}