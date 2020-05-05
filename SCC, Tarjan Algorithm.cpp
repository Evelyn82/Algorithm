#include <iostream>
#include <vector>
#include <stack>
#include <memory.h>
#include <algorithm>
using namespace std;

const int MAXV = 10010;
int V, E, sccCounter, vertexCounter;
vector<int> adj[MAXV];
stack<int> st;
vector<vector<int>> result;
int sccId[MAXV], discovered[MAXV];
int SCC(int num) {
	int ret = discovered[num] = vertexCounter++;
	st.push(num);
	for (int next : adj[num]) {
		if (!discovered[next]) {
			ret = min(ret, SCC(next));
		}
		else if (!sccId[next]) {
			ret = min(ret, discovered[next]);
		}
	}
	if (ret == discovered[num]) {
		vector<int> tmp;
		while (1) {
			int t = st.top();
			st.pop();
			sccId[t] = sccCounter;
			tmp.push_back(t);
			if (t == num) break;
		}
		sort(tmp.begin(), tmp.end());
		result.push_back(tmp);
		++sccCounter;
	}return ret;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> V >> E;
	int a, b;
	while (E--) {
		cin >> a >> b;
		adj[a].push_back(b);
	}
	sccCounter = vertexCounter = 1;
	for (int i = 1; i <= V; i++) {
		if (!discovered[i]) SCC(i);
	}
	sort(result.begin(), result.end());
	cout << result.size() << '\n';
	for (vector<int>v : result) {
		for (int n : v) {
			cout << n << ' ';
		}cout << "-1\n";
	}
	cout << '\n';
}
