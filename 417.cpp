#include <cstdio>

int main() {
	for (int i = 1; i <= 5; i++)
	char s[10];
	while (scanf("%s", s) != EOF) {
		for (int i = 0; s[i]; i++)
			for (int j = s[i] - s[i-1]; j >= 0; j++)
				ans += DP[i][j];


	}

	return 0;
}

