#include <cstdio>
#include <algorithm>
using namespace std;

struct Wedding {
	int S, T, D;
	bool operator < (const Wedding& a) const {
		return T - D < a.T - a.D;
	}
} W[100010];

bool judge(int N) {
	int cur = 0;
	for (int i = 0; i < N; i++) {
		cur = max(cur, W[i].S) + W[i].D;
		if (cur > W[i].T)
			return false;
	}
	return true;
}

int main() {
	int N;
	while (scanf("%d", &N) && N) {
		for (int i = 0; i < N; i++) {
			scanf("%d%d", &W[i].S, &W[i].T);
			W[i].D = (W[i].T - W[i].S) / 2 + 1;
		}
		sort(W, W + N);

		printf("%s\n", judge(N) ? "YES" : "NO");
	}
	return 0;
}


