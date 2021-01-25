#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>
using namespace std;

struct Point {
	int x, y;
	Point() {}
	Point(int _x, int _y) : x(_x), y(_y) {}
	bool operator<(const Point& other) const {
		if (this->y == other.y) return this->x < other.x;
		else return this->y < other.y;
	}
};
bool cmp(const Point& a, const Point& b) {
	return a.x < b.x;
}
int dist(Point a, Point b) {
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<Point> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].x >> a[i].y;
	}
	sort(a.begin(), a.end(), cmp);
	set<Point> candidate = { a[0],a[1] };
	int ans = dist(a[0], a[1]);
	int start = 0;
	for (int i = 2; i < n; i++) {
		Point now = a[i];
		while (start < i) {
			auto p = a[start];
			int x = now.x - p.x;
			if (x * x > ans) {
				candidate.erase(p);
				start += 1;
			}
			else break;
		}
		
		// d의 값에 +1 하는 이유 -> 소수 부분으로 인해 영향을 받을 수 있으니, 각 bound 마다 범위를 1씩 더해 넉넉하게 해줌.
		// +1 안해도 AC
		int d = (int)sqrt((double)ans) + 1;
		
		auto lower_point = Point(-1e5, now.y - d);
		auto upper_point = Point(1e5, now.y + d);
		
		auto lower = candidate.lower_bound(lower_point);
		auto upper = candidate.upper_bound(upper_point);
		
		for (auto it = lower; it != upper; it++) {
			int d = dist(now, *it);
			if (d < ans) ans = d;
		}
		candidate.insert(now);
	}
	cout << ans << '\n';
}
