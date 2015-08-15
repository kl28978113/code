#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#pragma comment(linker, "/STACK:102400000,102400000")  
vector<int> F[100010];

const long long MOD = 1e9 + 7;
long long A[100010] = {1}, res;

int DFS(int node, int fa) {
	int n = F[node].size();

	int sum = 1, cnt = 0, num = 0;

	for (int i = 0; i < n; i++) {
		int son = F[node][i];
		if (son == fa) continue;
		num++;
		int len = DFS(son, node);
		cnt += (len > 1);
		sum += len;
	}

	if (cnt > 2)
		return res = 0;

	if (cnt != 0) res = res * 2 % MOD;
	res = res * A[num - cnt] % MOD;

	return sum;
}

int main() {
	int T, cas = 0;
	scanf("%d", &T);
	for (int i = 1; i <= 100010; i++)
		A[i] = A[i-1] * i % MOD;

	while (T--) {
		int n; 
		scanf("%d", &n);
		int x, y;
		res = 1;
		for (int i = 1; i <= n; i++)
			F[i].clear();

		for (int i = 1; i < n; i++) {
			scanf("%d%d", &x, &y);
			F[y].push_back(x);
			F[x].push_back(y);
		}

		if (n > 1)
			res = res * 2 % MOD;
		DFS(1, 0);
		printf("Case #%d: %lld\n", ++cas, res);
	}
	return 0;
}
