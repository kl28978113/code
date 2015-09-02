#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

set<int> hehe;
vector<int> A[4010];


int main() {
	int n, m, a, b;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d%d", &a, &b);
		if (a > b)
			swap(a, b);
		hehe.insert(a * 10000 + b);
		A[a].push_back(b);
		A[b].push_back(a);
	}

	int ans = 0x3f3f3f3f;
	for (int i = 0; i < n; ++i) {
		int M1 = A[i].size();
		for (int j = 0; j < M1; ++j) {
			for (int k = j+1; k < M1; ++k) {
				int x = A[i][j];
				int y = A[i][k];
				if (x > y)
					swap(x, y);
				if (hehe.count(x * 10000 + y)) {
					int tmp = A[i].size() + A[x].size() + A[y].size() -6;
					ans = min(ans, tmp);
			}
			}
		}
	}
	if (ans != 0x3f3f3f3f)
		printf("%d\n", ans);
	else
		printf("%d\n", -1);

	return 0;
}
