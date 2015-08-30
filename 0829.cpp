#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int flag;
vector<int> T[1010];
int V[1010], n, cnt;

void dfs(int x, int pre) {
	if (flag == true)
		return;

	if (T[x].size() != 2) {
		flag = true;
		for (int i = 1; i <=n; i++)
			if (V[i])
			printf("%d, ", i);
		printf("hehe");
	}

	if (V[x] && cnt != n+1) {
		flag = true;

		for (int i = 1; i <=n; i++)
			if (V[i])
			printf("%d, ", i);
		printf("cnt = %d", cnt);
	}
			

	V[x] = 1;
	cnt++;
	for (int i = 0; i < T[x].size(); i++) {
		if (T[x][i] == pre)
			continue;
		dfs(T[x][i], x);
	}
}


int main() {
	while (scanf("%d", &n) != EOF) {
		flag = false;
		for (int i = 0; i <= n+5; i++) {
			T[i].clear();
			V[i] = 0;
		}

		int x, y;
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &x, &y);
			T[x].push_back(y);
			T[y].push_back(x);
		}

		cnt = 0;
		if (cnt == )
		dfs(1, 0);

		flag ? puts("NO") : puts("YES");
	}
	return 0;
}
