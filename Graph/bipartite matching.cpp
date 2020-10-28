#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 101;
int n, m;
bool adj[MAXN][MAXN];
vector<int> aMatch, bMatch;
vector<bool> visited;

bool matching(int a) {
	if (visited[a]) return false;
	visited[a] = true;

	for (int b = 0; b < m; ++b) {
		if (adj[a][b]) {
			if (bMatch[b] == -1 || matching(bMatch[b])) {
				aMatch[a] = b;
				bMatch[b] = a;
				return true;
			}
		}
	}return false;
}

int bipartiteMatch() {
	aMatch = vector<int>(n, -1);
	bMatch = vector<int>(m, -1);
	
	int ret = 0;
	for (int start = 0; start < n; ++start) {
		visited = vector<bool>(n, false);
		if (matching(start)) ++ret;
	}
	// maximum matching
	return ret;
}
