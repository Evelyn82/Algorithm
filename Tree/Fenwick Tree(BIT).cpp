vector<long long> fw;

long long sum(int pos) {
	long long ret = 0;
	while (pos > 0) {
		ret += fw[pos];
		pos -= (pos & -pos);
	}
	return ret;
}

void add(int pos, long long diff) {
	while (pos < tree.size()) {
		fw[pos] += diff;
		pos += (pos & -pos);
	}
}
