#include <iostream>
#include <vector>
using namespace std;

struct FenwickTree {
	vector<long long> ary;
	vector<long long> tree;
	FenwickTree(int n) : ary(n + 1), tree(n + 1) {}

	long long sum(int pos) {
		++pos;
		long long ret = 0;
		while (pos > 0) {
			ret += tree[pos];
			pos &= (pos - 1);
			//pos -= (pos & -pos);
		}
		return ret;
	}
	void add(int pos, long long diff) {
		++pos;
		while (pos < tree.size()) {
			tree[pos] += diff;
			pos += (pos & -pos);
		}
	}
};
