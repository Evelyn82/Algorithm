#include <vector>
#include <cmath>
using namespace std;

vector<int> minFactor;
void eratosthenes(int n) {
	minFactor.resize(n + 1);
	minFactor[0] = minFactor[1] = -1;
	for (int i = 2; i <= n; i++) {
		minFactor[i] = i;
	}
	int sqrtn = (int)sqrt(n);
	for (int i = 2; i <= sqrtn; i++) {
		if (minFactor[i] == i) {
			for (int j = i * i; j <= n; j += i) {
				if (minFactor[j] == j) {
					minFactor[j] = i;
				}
			}
		}
	}
}
vector<int> PrimeFactorization(int n) {
	vector<int> ret;
	while (n > 1) {
		ret.push_back(minFactor[n]);
		n /= minFactor[n];
	}return ret;
}
