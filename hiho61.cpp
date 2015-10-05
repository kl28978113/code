#include <cstdio>

int N, M, A[50010];
char S[50010], C[10];

int main() {
	scanf("%d%d%s", &N, &M, S);
	for (int i = 0; i < N; i++)
		A[i] = S[i] - 'A';

	int L, R, K, op, cur = 0;
	for (int i = 0; i < M; i++) {
		scanf("%*s%d", &op);
		if (op == 1) {
			scanf("%d%d%s", &L, &R, C);
			L = (L - 1 + cur) % N;
			R = (R - 1 + cur) % N;

			if (L <= R) {
				for (int i = L; i <= R; i++)
					A[i] = C[0] - 'A';
			} else {
				for (int i = L; i <= N - 1; i++)
					A[i] = C[0] - 'A';
				for (int i = 0; i <= R; i++)
					A[i] = C[0] - 'A';
			}

		} else if (op == 2) {
			scanf("%d%d%d", &L, &R, &K);
			L = (L - 1 + cur) % N;
			R = (R - 1 + cur) % N;

			if (L <= R) {
				for (int i = L; i <= R; i++)
					A[i] += K;
			} else {
				for (int i = L; i <= N - 1; i++)
					A[i] += K;
				for (int i = 0; i <= R; i++)
					A[i] += K;
			}
		} else if (op == 3) {
			scanf("%d", &K);
			cur = (cur + K) % N;
		} else {
			scanf("%d%d", &L, &R);
			L = (L - 1 + cur) % N;
			R = (R - 1 + cur) % N;

			int cnt = 0;
			 if (L <= R) {
				for (int i = L; i <= R; i++)
					A[i] += ++cnt;
			} else {
				for (int i = L; i <= N - 1; i++)
					A[i] += ++cnt;
				for (int i = 0; i <= R; i++)
					A[i] += ++cnt;
			}
		}
	}

	for (int i = 0; i < N; i++)
		printf("%c", (A[(i + cur) % N] % 26) + 'A');
	puts("");
	return 0;
}
