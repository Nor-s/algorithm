#include <math.h>
#include <vector>
using namespace std;
namespace VECTOR2
{

    const double PI = 2.0 * acos(0.0);

    struct vector2
    {
        double x, y;
        explicit vector2(double x_ = 0., double y_ = 0) : x(x_), y(y_)
        {
        }
        bool operator==(const vector2 &rhs) const
        {
            return x == rhs.x && y == rhs.y;
        }
        bool operator<(const vector2 &rhs) const
        {
            return x != rhs.x ? x < rhs.x : y < rhs.y;
        }
        vector2 operator+(const vector2 &rhs) const
        {
            return vector2(x + rhs.x, y + rhs.y);
        }
        vector2 operator-(const vector2 &rhs) const
        {
            return vector2(x - rhs.x, y - rhs.y);
        }
        vector2 operator*(double rhs) const
        {
            return vector2(x * rhs, y * rhs);
        }
        double norm() const { return hypot(x, y); } //벡터의 길이
        vector2 normalize() const
        {
            return vector2(x / norm(), y / norm());
        }
        double polar() const { return fmod(atan2(y, x) + 2 * PI, 2 * PI); }
        double dot(const vector2 &rhs) const
        {
            return x * rhs.x + y * rhs.y;
        }
        double cross(const vector2 &rhs) const
        {
            return x * rhs.y - rhs.x * y;
        }
        vector2 project(const vector2 &rhs) const
        {
            vector2 r = rhs.normalize();
            return r * r.dot(*this);
        }

        //반시계-> 양수
        double ccw(vector2 a, vector2 b)
        {
            return a.cross(b);
        }
        double ccw(vector2 p, vector2 a, vector2 b)
        {
            return ccw(a - p, b - p);
        }
        //두직선의교차점
        // p = (c-a) x dir2 / dir1 x dir2
        bool lineIntersection(vector2 a, vector2 b, vector2 c, vector2 d, vector2 &p)
        {
            vector2 dir1 = b - a;
            vector2 dir2 = d - c;
            double det = dir1.cross(dir2);
            if (fabs(det) < DBL_EPSILON)
                return false;
            p = a + dir1 * ((c - a).cross(dir2) / det);
            return true;
        }
        //평행한 두 선분일때 한점에서겹치는지확인
        bool parallelSegments(vector2 a, vector2 b, vector2 c, vector2 d, vector2 &p)
        {
            if (b < a)
                std::swap(a, b);
            if (d < c)
                std::swap(c, d);
            if (ccw(a, b, c) != 0 || b < c || d < a)
                return false;
            if (a < c)
                p = c;
            else
                p = a;
            return true;
        }
        bool inBoundingRectangle(vector2 p, vector2 a, vector2 b)
        {
            if (b < a)
                std::swap(a, b);
            return p == a || p == b || (a < p && p < b);
        }
        bool segmentIntersection(vector2 a, vector2 b, vector2 c, vector2 d, vector2 &p)
        {
            if (!lineIntersection(a, b, c, d, p))
                return parallelSegments(a, b, c, d, p);
            return inBoundingRectangle(p, a, b) &&
                   inBoundingRectangle(p, c, d);
        }
        bool segmentIntersects(vector2 a, vector2 b, vector2 c, vector2 d)
        {
            double ab = ccw(a, b, c) * ccw(a, b, d);
            double cd = ccw(c, d, a) * ccw(c, d, b);
            if (ab == 0 && cd == 0)
            {
                if (b < a)
                    std::swap(a, b);
                if (d < c)
                    std::swap(c, d);
                return !(b < c || d < a);
            }
            return ab <= 0 && cd <= 0;
        }

        vector2 nomalVector()
        {
            return vector2(-y, x).normalize();
        }
        double howMuchCloser(vector2 p, vector2 a, vector2 b)
        {
            return (b - p).norm() - (a - p).norm();
        }
        vector2 perpendicularFoot(vector2 p, vector2 a, vector2 b)
        {
            return a + (p - a).project(b - a);
        }
        double pointToLine(vector2 p, vector2 a, vector2 b)
        {
            return (p - perpendicularFoot(p, a, b)).norm();
        }
    };

}
typedef vector<vector2> polygon;
//반시계-> 양수
double cross(const vector2 &rhs) const
{
    return x * rhs.y - rhs.x * y;
}
double ccw(vector2 a, vector2 b)
{
    return a.cross(b);
}
double ccw(vector2 p, vector2 a, vector2 b)
{
    return ccw(a - p, b - p);
}
//points을 포함하는 최소 블록 다각형을 찾는다.
polygon gifWarp(const vector<vector2> &points)
{
    int n = points.size();
    polygon hull;
    vector2 pivot = *min_element(points.begin(), points.end());
    hull.push_back(pivot);
    while (true)
    {
        vector2 ph = hull.back(), next = points[0];
        for (int i = 1; i < n; ++i)
        {
            // cross: 전에 선택한것을 기준으로 i번째 점이 후보에 반시계방향에 있을시 (왼쪽에 있을시) 업데이트.
            double cross = ccw(ph, next, points[i]);
            // dist: 평행할 때 지금보다 더 멀리 떨어저있는거라면 업데이트 시키라는 것.
            double dist = (next - ph).norm() - (points[i] - ph).norm();
            if (cross > 0 || (cross == 0 && dist < 0))
                next = points[i];
        }
        if (next == pivot)
            break;
        hull.push_back(next);
    }
    return hull;
}

double area(const vector<vector2> &p)
{ // 오목다각형 넓이구하기
    double ret = 0;
    for (int i = 0; i < p.size(); ++i)
    {
        int j = (i + 1) % p.size();
        ret += p[i].x * p[j].y - p[j].x * p[i].y;
    }
    return fabs(ret) / 2.0;
}