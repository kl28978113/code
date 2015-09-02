#include <cstdio>
#include <set>
using namespace std;

set<int> S;

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		S.clear();
		int N, V, K;
		scanf("%d%d%d", &N, &V, &K);
		int v[110], m[110], DP[1010] = {0};
		for (int i = 0; i < N; i++) 
			scanf("%d", &v[i]);
		for (int i = 0; i < N; i++) 
			scanf("%d", &m[i]);



		for (int i = 0; i < N; i++)
			for (int j = V; j >= v[i]; j--) {
				S.insert(DP[j-v[i]] + m[i]);
				if (DP[j] < DP[j-v[i]] + m[i]) {
					DP[j] = DP[j-v[i]] + m[i];
				}
			}

		if (S.size() < K) {
			puts("0");
			continue;
		}

		set<int>::iterator it = S.end();
		for (int i = 0; i < K; i++)
			it--;

		printf("%d\n", *it);
	}
	return 0;
}


