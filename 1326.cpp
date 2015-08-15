#include <cstdio>
#include <map>
using namespace std;

int bitcount(int x) {
	return x == 0 ? 0 : bitcount(x/2) + (x&1);
}

int main() {
	int N, A[30];
	char s[1010];
	map<int, int> table;

	while (scanf("%d", &N) != EOF) {
		for (int i = 0; i < N; i++) {
			scanf("%s", s);
			A[i] = 0;
			for (int j = 0; s[j] != '\0'; j++)
				A[i] ^= (1 << (s[j] - 'A'));
		}

		int n1 = N / 2;
		int n2 = N - n1;
		table.clear();
		for (int i = 0; i < (1<<n1); i++) {
			int x = 0;
			for (int j = 0; j < n1; j++) 
				if (i & (1<<j)) x ^= A[j];
			if (!table.count(x) || bitcount(table[x]) < bitcount(i))
				table[x] = i;
		}

		int ans = 0;
		for (int i = 0; i < (1<<n2); i++) {
			int x = 0;
			for (int j = 0; j < n2; j++)
				if (i & (1<<j)) x ^= A[n1+j];
			if (table.count(x) && bitcount(ans) < bitcount(table[x]) + bitcount(i))
				ans = (i<<n1)^table[x];
		}

		printf("%d\n", bitcount(ans));
		for (int i = 0; i < N; i++)
			if (ans & (1<<i))
				printf("%d ", i+1);
		printf("\n");
	}
	return 0;
}


