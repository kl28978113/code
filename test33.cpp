#include <cstdio>

int main() {
	char str[200];
	while (scanf("%s", str) != EOF) {
		int vis[200] = {0}, MAX = 0;
		for (int i = 0; str[i]; i++)
			if (str[i] > MAX)
				MAX = str[i];

		for (int i = 0; str[i]; i++) {
			printf("%c", str[i]);
			if (str[i] == MAX) printf("(max)");
		}
		puts("");
	}
	return 0;
}
