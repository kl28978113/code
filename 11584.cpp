#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

char str[1010];
int DP[1010];

bool judge(int l, int r) {
	while (l < r) {
		if (str[l] != str[r])
			return false;
		l++, r--;
	}
	return true;
}

int main() {
	int n;
	scanf("%d", &n);
	while(n--) {
		scanf("%s", str + 1);
		int len = strlen(str + 1);
		memset(DP, 0x3f3f3f3f, sizeof(DP));
		DP[0] = 0;

		for (int i = 1; i <= len; i++)
			for (int j = 1; j <= i; j++)
				if (judge(j, i))
					DP[i] = min(DP[i], DP[j-1] + 1);

		printf("%d\n", DP[len]);
	}
	return 0;
}
