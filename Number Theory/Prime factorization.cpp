#include <vector>
#include <cmath>
using namespace std;

vector<int> primeFactor(int n) {
	vector<int> ret;
	int sqrtn = (int)sqrt(n);
	for (int i = 2; i <= sqrtn; i++) {
		while (n % i == 0) {
			n /= i;
			ret.push_back(i);
		}
	}
	if (n > 1) ret.push_back(n);
	return ret;
}
