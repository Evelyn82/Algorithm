#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1e3 + 1;
int N, ary[MAXN], d[MAXN];
int lis(int start) {
	int& ref = d[start];
	if (ref != -1) return ref;

	ref = 1;
	for (int i = start + 1; i < N; i++) {
		if (ary[start] < ary[i]) {
			ref = max(ref, lis(i) + 1);
		}
	}return ref;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> ary[i];
		d[i] = -1;
	}
	for (int i = 0; i < N; i++) lis(i);
	sort(d, d + N);
	cout << d[N - 1] << '\n';
}