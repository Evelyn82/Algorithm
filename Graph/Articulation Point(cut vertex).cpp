const int MAXV = 1e4 + 1;
int V, E, discovered[MAXV], counter = 1;
vector<int> v[MAXV];
vector<int> isCutVertex;

int findCutVertex(int n, bool isRoot) {
	discovered[n] = counter++;
	int ret = discovered[n];

	int children = 0;
	for (int k = 0; k < v[n].size(); k++) {
		int next = v[n][k];
		if (!discovered[next]) {
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
	for (int i = 1; i < MAXV; i++) {
		if (!discovered[i]) {
			counter = 1;
			findCutVertex(i, true);
		}
	}
	sort(isCutVertex.begin(), isCutVertex.end());
	isCutVertex.erase(unique(isCutVertex.begin(), isCutVertex.end()), isCutVertex.end());
}
