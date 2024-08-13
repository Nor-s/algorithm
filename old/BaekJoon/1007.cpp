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

double magnitude(double a, double b) {
    return sqrt(a*a + b*b);
}

void solve(int idx, int k,  double x, double y) {
    if(k == N) {
        double m = magnitude(x, y);
        if(answer > m)
            answer = m;
        return;
    }
    if(idx >= N) {
        return;
    }
    
    solve(idx+1, k + 2, x - 2*coords[idx].first, y - 2*coords[idx].second);
    solve(idx+1, k, x, y);
}

int main() {
    cin>>T;
    while(T--) {
        cin>>N;
        answer = 1e10;
        coords = vector<pair<double, double> > (N);
        double sumx = 0, sumy = 0;
        for(int i = 0; i < N; i++) {
            double a, b;
            cin>>a>>b;
            coords[i] = (make_pair(a, b));
            sumx += a;
            sumy += b;
        }
        
        solve(0, 0, sumx, sumy);
        printf("%0.6lf\n", answer);
    }
}