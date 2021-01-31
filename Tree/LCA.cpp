#include <iostream>
#include <vector>
using namespace std;

int n, m;
int parents[100001][21];
vector<vector<int>> adj;
vector<bool> visit;
vector<int> d;
void dfs(int n, int depth) {
	visit[n] = true;
	d[n] = depth;
	for (int next : adj[n]) {
		if (visit[next]) continue;
		parents[next][0] = n;
		dfs(next, depth + 1);
	}
}
void dp() {
	for (int j = 1; j < 21; j++) {
		for (int i = 1; i <= n; i++) {
			parents[i][j] = parents[parents[i][j - 1]][j - 1];
		}
	}
}
int LCA(int x, int y) {
	if (d[x] > d[y]) swap(x, y);
	for (int k = 20; k >= 0; k--) {
		if (d[y] - d[x] >= (1 << k)) {
			y = parents[y][k];
		}
	}
	if (x == y) return x;
	for (int k = 20; k >= 0; k--) {
		if (parents[x][k] != parents[y][k]) {
			x = parents[x][k];
			y = parents[y][k];
		}
	}return parents[x][0];
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	adj.resize(n + 1);
	visit.resize(n + 1, false);
	d.resize(n + 1, 0);
	int a, b;
	for (int k = 0; k < n - 1; k++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1, 0);
	dp();

	cin >> m;
	for (int k = 0; k < m; k++) {
		cin >> a >> b;
		cout << LCA(a, b) << '\n';
	}
}
