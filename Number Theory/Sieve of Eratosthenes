#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

const int MAXN = 30001;
vector<bool> prime;
void solution(int n) {
	prime.resize(MAXN + 1, true);
	prime[0] = prime[1] = false;
  
	int sqrtn = int(sqrt(n));
	for (int i = 2; i <= sqrtn; i++) {
		if (prime[i]) {
			// 시작지점을 i*i로 설정
			// 3 x i는 3의 배수를 처리할때 이미 모두 false처리됨 
			for (int j = i * i; j < MAXN; j += i) {
				prime[j] = false;
			}
		}
	}
}
