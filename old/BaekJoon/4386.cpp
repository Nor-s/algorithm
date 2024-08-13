#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <limits.h>
#include <float.h>

using namespace std;
int n;
vector<vector<double> > adjList;

void MST() {
    vector<double> dist(n, INT32_MAX);

    priority_queue<pair<double, int> > q;
    q.push(make_pair(0, 0));

    while(!q.empty()) {
        int here = q.top().second;
        double cost = -q.top().first;
        q.pop();
        if(dist[here] <= cost)
            continue;
        dist[here] = cost;

        for(int there = 0; there < adjList[here].size(); there++) {
            double cost2 = adjList[here][there];
            if(dist[there] == INT32_MAX && there != here) {
                q.push(make_pair(-cost2, there));
            }
        }
    }
    cout.precision(3);
    cout<<accumulate(dist.begin(), dist.end(), (double)0);
}

double dist(pair<double, double>& a, pair<double, double>& b) {
    return sqrt(pow(a.first-b.first,2) + pow(a.second - b.second,2));
}

int main() {
    cin>>n;
    adjList = vector<vector<double> >(n, vector<double>(n, 0));
    vector<pair<double, double> > star;
    
    for(int i = 0; i < n; i++) {
        double x, y;
        cin>>x>>y;
        star.push_back(make_pair(x, y));
    }
    for(int i = 0 ; i < n; i++) {
        for(int j = 0; j < n; j++) {
            adjList[i][j] = adjList[j][i] = dist(star[i], star[j]);
        }
    }
    MST();
}