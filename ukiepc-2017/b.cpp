#include <bits/stdc++.h>

using namespace std;

struct pt {
    double x, y;
    pt(double x, double y): x(x), y(y) {}

    pt operator -(pt other) {
        return pt(x - other.x, y - other.y);
    }

    pt operator *(double t) {
        return pt(x * t, y * t);
    }

    double norm() {
        return sqrt(x * x + y * y);
    }
};

double dot_prod(pt a, pt b) {
    return a.x * b.x + a.y * b.y;
}

double cross_prod(pt a, pt b) {
    return a.x * b.y - a.y * b.x;
}

double ccw(pt a, pt b, pt c) {
    return cross_prod(b - a, c - a);
}

pt projection(pt a, pt b) {
    double t = dot_prod(a, b) / b.norm() / b.norm();
    return b * t;
}

vector<pt> graham_scan(vector<pt>& pts, int n) {
    auto base = 0;
    for (int i = 1; i < n; i++) {
        if (pts[i].y < pts[base].y || (fabs(pts[i].y - pts[base].y) < 1e-9 && pts[i].x < pts[base].x)) {
            base = i;
        }
    }
    swap(pts[0], pts[base]);
    sort(pts.begin() + 1, pts.end(), [&pts, &base](pt a, pt b) {
        double cp = cross_prod(a - pts[0], b - pts[0]);
        if (fabs(cp) < 1e-9) {
            return (a - pts[0]).norm() < (b - pts[0]).norm();
        }
        return cp > 0;
    });
    vector<pt> hull;
    for (int i = 0; i < pts.size(); i++) {
        while (hull.size() > 1 && ccw(*(hull.rbegin() + 1), *hull.rbegin(), pts[i]) <= 1e-9) {
            hull.pop_back();
        }
        hull.push_back(pts[i]);
    }
    return hull;
}

double dist(pt a, pt b, pt c) {
    pt proj = projection(a - b, c - b);
    pt d = proj - (a - b);
    return d.norm();
}

int main() {
    int n;
    scanf("%d", &n);
    vector<pt> pts;
    for (int i = 1; i <= n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        pts.push_back(pt(x, y));
    }

    auto hull = graham_scan(pts, n);

    double mi = 1e20;
    for (int i = 0; i < hull.size(); i++) {
        double ma = 0;
        for (int j = 0; j < hull.size(); j++) {
            ma = max(ma, dist(hull[j], hull[i], hull[(i + 1) % hull.size()]));
        }
        mi = min(mi, ma);
    }

    printf("%.9lf\n", mi);

    return 0;
}
