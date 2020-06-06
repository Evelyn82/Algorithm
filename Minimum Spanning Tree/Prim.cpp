#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool visit[1001];
vector<pair<int, int>> a[1001];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		a[from].push_back({ to,cost });
		a[to].push_back({ from,cost });
	}
  
	priority_queue<pair<int, int>> pq;
	for (auto &p : a[1]) {
		pq.push({ -p.second, p.first });
	}
	visit[1] = true;
  
	int ans = 0;
	while (!pq.empty()) {
		auto p = pq.top();
		pq.pop();
		if (visit[p.second]) continue;
		visit[p.second] = true;
		ans += -p.first;
		int x = p.second;
		for (auto &p : a[x]) {
			pq.push({ -p.second, p.first });
		}
    
		// 아래코드로 변경하면 메모리는 적지만
		// 시간이 더 소요된다.
		/*for (auto &p : v[x]) {
			if (!visit[p.first])
				q.push({ -p.second, p.first });
		}*/
	}
	printf("%d\n", ans);
}
