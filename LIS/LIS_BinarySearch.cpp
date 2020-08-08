#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1E6 + 1;
int N, ary[MAXN], d[MAXN];
int search(int left, int right, int num) {
	if (left == right) return left;
	if (left + 1 == right) return (d[left] >= num) ? left : right;

	int mid = (left + right) / 2;
	if (d[mid] == num) return mid;
	else if (d[mid] > num) return search(left, mid, num);
	else return search(mid + 1, right, num);
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> ary[i];
		d[i] = MAXN;
	}
	d[0] = -MAXN;
	int idx = 1;
	d[1] = ary[1];
	for (int i = 2; i <= N; i++) {
		if (d[idx] < ary[i]) {
			d[++idx] = ary[i];
		}
		else {
			int next = search(1, idx, ary[i]);
			d[next] = ary[i];
		}
	}
	int ans = 0;
	for (int k = 1; k <= N; k++) {
		if (d[k] != MAXN && ans < d[k]) {
			ans = k;
		}
	}
	cout << ans << '\n';
}
