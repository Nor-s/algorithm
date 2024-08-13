#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>

#define ll long long

using namespace std;
int N;
vector<pair<ll, ll> > xy;


double tArea(const pair<ll, ll>& a, const pair<ll, ll>& b) {
    return a.first*b.second - a.second*b.first;
}

double area() {
    double sum = 0;
    for(int i = 0; i < N; i++) {
        int j = (i+1)%N;
        double a = tArea(xy[i], xy[j]);
        sum += a;
    }
    return fabs(sum)/2.0;
}

int main() {
    cin>>N;
    for(int i = 0; i < N; i++) {
        ll a, b;
        cin>>a>>b;
        xy.push_back({a, b});
    }
    printf("%0.1lf", area());
}