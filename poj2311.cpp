#include <cstdio>
#include <set>
#include <cstring>
using namespace std;

int g[210][210];

int grundy(int W, int H) {
	if (g[W][H] != -1) return g[W][H];

	set<int> s;
	for (int i = 2; i <= W / 2; i++) s.insert(grundy(i, H) ^ grundy(W - i, H));
	for (int i = 2; i <= H / 2; i++) s.insert(grundy(W, i) ^ grundy(W, H - i));

	int res = 0;
	while (s.count(res)) res++;
	return g[W][H] = res;
}

int main() {
	int W, H;
	memset(g, -1, sizeof(g));
	while (scanf("%d%d", &W, &H) != EOF) {
		if (grundy(W, H)) puts("WIN");
		else puts("LOSE");
	}
	return 0;
}
