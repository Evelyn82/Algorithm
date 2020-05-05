#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;

const int MAXV = 1e4 + 1;
int V, E, discovered[MAXV], couter = 1;
bool visited[MAXV];
vector<int> v[MAXV];
vector<int> isCutVertex;
int findCutVertex(int n, bool isRoot) {
	discovered[n] = couter++;
	int ret = discovered[n];

	int children = 0;
	for (int k = 0; k < v[n].size(); k++) {
		int next = v[n][k];
		if (discovered[next] == -1) {
			children++;
			int subTree = findCutVertex(next, false);
			if (!isRoot && subTree >= discovered[n]) {
				isCutVertex.push_back(n);
			}ret = min(ret, subTree);
		}
		else ret = min(ret, discovered[next]);
	}
	if(isRoot) if(children>=2) isCutVertex.push_back(n);
	return ret;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> V >> E;
	int a, b;
	for (int k = 0; k < E; k++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
		visited[a] = true;
		visited[b] = true;
	}
	memset(discovered, -1, sizeof(discovered));
	for (int i = 1; i < MAXV; i++) {
		if (visited[i] && discovered[i] == -1) {
			couter = 1;
			findCutVertex(i, true);
		}
	}
	sort(isCutVertex.begin(), isCutVertex.end());
	isCutVertex.erase(unique(isCutVertex.begin(), isCutVertex.end()), isCutVertex.end());
	cout << isCutVertex.size() << '\n';
	if (isCutVertex.size() != 0) {
		for (int num : isCutVertex) cout << num << ' ';
		cout << '\n';
	}  
}
