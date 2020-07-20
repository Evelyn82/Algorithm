// O(n^2) 
// n = 1e4이면 O(1e8) = 1억
// 즉, n이 le4이상이면 Palindrome이 아닌 O(n)인 Manacher's algorithm으로 사용한다.

#include <iostream>
using namespace std;

const int MAXN = 2001;
int ary[MAXN], DP[MAXN][MAXN];
void initial(int n) {
  // 1자리
	for (int i = 0; i < n; i++) DP[i][i] = true;
  
  // 2자리
	for (int i = 0; i < n - 1; i++) {
		if (ary[i] == ary[i + 1]) {
			DP[i][i + 1] = true;
		}
	}
  
  // 3자리 이상
	for (int k = 2; k <= n - 1; k++) {
		for (int i = 0; i < n - k; i++) {
			int j = i + k;
			if (ary[i] == ary[j] && DP[i + 1][j - 1]) {
				DP[i][j] = true;
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N, M, a, b;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> ary[i];
	initial(N);
	cin >> M;
	while (M--) {
		cin >> a >> b;
    
    // a, b구간이 Palindrome일 경우 1출력
		if (DP[a - 1][b - 1]) cout << 1 << '\n';
		else cout << 0 << '\n';
	}
}
