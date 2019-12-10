#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
struct RSQ {
	int n;
	vector<ll> rangeSum;
	vector<ll> lazy;
	RSQ(const vector<ll>& array) {
		n = array.size();
		rangeSum.resize(n * 4, 0);
		lazy.resize(n * 4, 0);
		init(array, 0, n - 1, 1);
	}
	ll init(const vector<ll>& array, int left, int right, int node) {
		if (left == right) return rangeSum[node] = array[left];
		int mid = (left + right) / 2;
		ll leftSum = init(array, left, mid, node * 2);
		ll rightSum = init(array, mid + 1, right, node * 2 + 1);
		return rangeSum[node] = leftSum + rightSum;
	}
	void update_lazy(int left, int right, int node) {
		if (lazy[node] != 0) {
			rangeSum[node] += (right - left + 1) * lazy[node];
			if (left != right) {
				lazy[node * 2] += lazy[node];
				lazy[node * 2 + 1] += lazy[node];
			}
			lazy[node] = 0;
		}
	}
	void update_range(int left, int right, int node, int nodeleft, int noderight, ll diff) {
		update_lazy(nodeleft, noderight, node);
		if (right < nodeleft || noderight < left) return;
		if (left <= nodeleft && noderight <= right) {
			rangeSum[node] += (noderight - nodeleft + 1) * diff;
			if (nodeleft != noderight) {
				lazy[node * 2] += diff;
				lazy[node * 2 + 1] += diff;
			}
			return;
		}
		int mid = (nodeleft + noderight) / 2;
		update_range(left, right, node * 2, nodeleft, mid, diff);
		update_range(left, right, node * 2 + 1, mid + 1, noderight, diff);
		rangeSum[node] = rangeSum[node * 2] + rangeSum[node * 2 + 1];
	}
	void update_range(int left, int right, int diff) {
		update_range(left, right, 1, 0, n - 1, diff);
	}
	ll sumQuery(int left, int right, int node, int nodeleft, int noderight) {
		update_lazy(nodeleft, noderight, node);
		if (right < nodeleft || noderight < left) return 0;
		if (left <= nodeleft && noderight <= right) return rangeSum[node];
		int mid = (nodeleft + noderight) / 2;
		return sumQuery(left, right, node * 2, nodeleft, mid) + sumQuery(left, right, node * 2 + 1, mid + 1, noderight);
	}
	ll sumQuery(int left, int right) {
		return sumQuery(left, right, 1, 0, n - 1);
	}
};
