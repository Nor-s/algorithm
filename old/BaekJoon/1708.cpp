#include <bits/stdc++.h>

#define vector2 pair<double, double>

using namespace std;

typedef vector<vector2> polygon;
int n;


vector2 sub(vector2 a, vector2 b) {
    return {a.first - b.first, a.second - b.second};
}
double ccw(vector2 a, vector2 b) {
    return a.first*b.second - a.second*b.first;
}
double ccw(vector2 p, vector2 a, vector2 b) {
    return ccw(sub(a, p), sub(b, p));
}

//points을 포함하는 최소 블록 다각형을 찾는다.
polygon gifWarp(const vector<vector2>& points) {
    int n = points.size();
    polygon hull;
    vector2 pivot = *min_element(points.begin(), points.end());
    hull.push_back(pivot);

    while(true) {
        vector2 ph = hull.back(), next = points[0];
        for(int i = 1; i < n; ++i) {
            // cross: 전에 선택한것을 기준으로 i번째 점이 후보에 반시계방향에 있을시 (왼쪽에 있을시) 업데이트.
            double cross = ccw(ph, next, points[i]);
            // dist: 평행할 때 지금보다 더 멀리 떨어저있는거라면 업데이트 시키라는 것.
            vector2 np = sub(next, ph);
            vector2 pp = sub(points[i], ph);
            double dist = hypot(np.first, np.second) - hypot(pp.first, pp.second);
            if(cross > 0 || (cross == 0 && dist < 0))
                next = points[i];
        }
        if(next == pivot) break;
        hull.push_back(next);
    }
    return hull;
}

int main() {
    cin>>n;
    polygon points;
    for(int i = 0; i < n; i++) {
        int a, b;
        cin>>a>>b;
        points.push_back({a, b});
    }
    points = gifWarp(points);
    cout<<points.size();
}