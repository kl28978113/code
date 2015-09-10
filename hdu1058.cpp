#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	long long DP[6000] = {1};
	int p2, p3, p5, p7, n;
	n = p2 = p3 = p5 = p7 = 0;
	while (DP[n] <= 2000000000) {
		DP[++n] = min(min(2 * DP[p2], 3 * DP[p3]), min(5 * DP[p5], 7 * DP[p7]));
		p2 += (DP[n] == 2 * DP[p2]);
		p3 += (DP[n] == 3 * DP[p3]);
		p5 += (DP[n] == 5 * DP[p5]);
		p7 += (DP[n] == 7 * DP[p7]);
	}

	while (scanf("%d", &n) && n) {
		printf("The %d%s humble number is %lld.\n", n, n%10 == 1 && n%100 != 11 ? "st" :
			n%10 == 2 && n%100 != 12 ? "nd" : n%10 == 3 && n%100 != 13 ? "rd" : "th", DP[n-1]);
	}
	return 0;
}
