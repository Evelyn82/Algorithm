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
	
	// sqrt(n) 까지만 탐색하는 이유
	// 자연수 n이 소수이기 필요 충분조건은 n이 sqrt(n)보다 크지 않는 어떤 소수로도 나눠지지 않는다.   
	// 즉, 몫과 나누는 수, 둘 중 하나는 반드시 sqrt(n) 이하이다.
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
		ret.push_back(n);
		n /= minFactor[n];
	}return ret;
}
