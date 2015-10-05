#include <cstdio>
#include <iostream>
using namespace std;

int main() {
	long long n, m, k;
	while (cin >> n >> m >> k) {
		long long sum = 0;
		k /= 2;
		for (int i = 1; i <= min(n, k-1) ; i++) {
			long long  x = min(m, k - i);
			sum += (n - i + 1) * (m + (m - x + 1)) * x;
		}
		cout << sum / 2 << endl;
	}
	return 0;
}
