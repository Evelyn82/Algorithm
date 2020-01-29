#include <vector>
#include <queue>
using namespace std;

const int INF = INT_MAX;
int V;
vector<pair<int, int>> adj[ ];
vector<int> dijkstra(int src) {
	vector<int> dist(V, INF);
	dist[src] = 0;

	priority_queue<pair<int, int>> pq;
	pq.push({ 0,src });
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();

		if (dist[here] < cost) continue;
		for (int i = 0; i < adj[here].size(); i++) {
			int there = adj[here][i].first;
			int nextDist = cost + adj[here][i].second;

			if (dist[there] > nextDist) {
				dist[there] = nextDist;
				pq.push({ -nextDist, there });
			}
		}
	}
	return dist;
}