// TLE
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lis(vector<int>& a) {
	if (a.empty()) return 0;
	int ret = 1;
	for (int i = 0; i < a.size(); i++) {
		vector<int> b;
		for (int j = i + 1; j < a.size(); j++) {
			if (a[i] < a[j]) b.push_back(a[j]);
		}
		ret = max(ret, lis(b) + 1);
	}
	return ret;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	vector<int> v;
	v.resize(N);
	for (int i = 0; i < N; i++) cin >> v[i];
	cout << lis(v) << '\n';
}
