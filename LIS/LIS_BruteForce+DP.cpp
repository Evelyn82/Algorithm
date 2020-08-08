#include <iostream>
#include <algorithm>
using namespace std;

int N, a[1001], d[1001];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
		d[i] = 1;
	}

	for (int i = 1; i < N; i++) {
		for (int j = i - 1; j >= 0; j--) {
			if (a[i] > a[j] && d[i] < d[j] + 1) {
				d[i] = d[j] + 1;
			}
		}
	}
	sort(d, d + N);
	cout << d[N - 1] << '\n';
}
