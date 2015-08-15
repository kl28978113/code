#include <cstdio>
#include <iostream>
#include <map>
using namespace std;

int main() {
	long long n, k, A[200040];
	while (cin >> n >> k) {
		map<long long, long long> L, R;
		long long ans = 0;
		for (int i = 1; i <= n; i++) {
			cin >> A[i];
			R[A[i]]++;
		}

		L[A[1]]++;
		R[A[1]]--;
		for (int i = 2; i < n; i++) {
			R[A[i]]--;
			if (A[i] % k == 0)
				ans += L[A[i] / k] * R[A[i] * k];
				//ans += L[A[i] / k] * (sum[A[i] * k] - cur[A[i] * k] - (k == 1 || A[i] == 0));
			L[A[i]]++;
		}
		cout << ans << endl;
	}

	return 0;
}
