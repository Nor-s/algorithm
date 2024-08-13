#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;
pair<double, double> a, aa;
pair<double, double> b, bb;

double cross(pair<double, double>& p1, pair<double, double>& p2) {
    return p1.first*p2.second - p2.first*p1.second;
}

double ccw(pair<double, double> p1, pair<double, double> p2) {
    return cross(p1, p2);
}
double ccw(pair<double, double>& p, pair<double, double>& p2, pair<double, double>& p3) {
    return ccw({p2.first - p.first, p2.second - p.second}, {p3.first - p.first, p3.second - p.second});
}

bool segmentIntersects() {
    double aaa = ccw(a, aa, b) * ccw(a, aa, bb);
    double bbb = ccw(b, bb, a) * ccw(b, bb, aa);
    if(aaa == 0 && bbb == 0) {
        if(aa < a) std::swap(a, aa);
        if(bb < b) std::swap(b, bb);
        return !(aa < b || bb < a);
    }
    return aaa <= 0 && bbb <= 0;
}

int main() {
    cin>>a.first>>a.second>>aa.first>>aa.second;
    cin>>b.first>>b.second>>bb.first>>bb.second;
    cout<<segmentIntersects();
}