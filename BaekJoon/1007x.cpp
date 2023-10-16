#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <utility>
#include <cmath>
#include <iomanip>

using namespace std;

int T;
int N;
vector<pair<double, double> > coords;
double answer;

double magnitude(pair<double, double>& a) {
    return sqrt(pow(a.first,2) + pow(a.second, 2));
}

void solve(int idx, vector<bool>& visited, pair<double, double> sum) {
    if(idx == N-1) {
        double m = magnitude(sum);
        if(answer > m)
            answer = m;
        return;
    }
    if(visited[idx]) 
        return solve(idx+1, visited, sum);
    visited[idx] = true;
    for(int i = 0; i < N; i++) {
        if(visited[i] == true) continue;

        visited[i] = true;
        double a = coords[i].first - coords[idx].first;
        double b = coords[i].second - coords[idx].second;
        solve(idx+1, visited, make_pair(sum.first + a, sum.second + b) );
        solve(idx+1, visited, make_pair(sum.first - a, sum.second - b) );
        visited[i] = false;
    }
    visited[idx] = false;
}

int main() {
    cin>>T;
    while(T--) {
        cin>>N;
        answer = 5.0/0.0;
        coords = vector<pair<double, double> > (N);
        for(int i = 0; i < N; i++) {
            double a, b;
            cin>>a>>b;
            coords[i] = (make_pair(a, b));
        }
        vector<bool> visited(N, false);
        solve(0, visited, make_pair(0, 0));
        printf("%0.12lf\n", answer);
    }
}