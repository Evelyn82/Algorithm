#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 1001
int parent[MAX];
struct Edge {
	int start, end, cost;
	bool operator < (Edge &other) {
		return cost < other.cost;
	}
};

int getParent(int x) {
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent[x]);
}

void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a < b)parent[b] = a;
	else parent[a] = b;
}

int findParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a == b) return 1;
	else return 0;
}

int main() {
	int N, M;
	cin >> N >> M;
	vector<Edge> v(M);
	for (int i = 0; i < M; i++) {
		cin >> v[i].start >> v[i].end >> v[i].cost;
	}
	sort(v.begin(), v.end());
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}
	int sum = 0;
	for (int i = 0; i < M; i++) {
		if (!findParent(v[i].start, v[i].end)) {
			sum += v[i].cost;
			unionParent(v[i].start, v[i].end);
		}
	}cout << sum << endl;
}
