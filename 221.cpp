#include <cstdio>
#include <algorithm>
using namespace std;

int N, T = 0;

struct Building {
	int x, y, w, d, h, id;
	bool operator < (const Building& a) const {
		return x != a.x ? x < a.x : y < a.y;
	}
} B[110], tmp[110];

bool judge(int k) {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		if (B[i].y >= B[k].y) continue;
		if (B[i].x + B[i].w <= B[k].x || B[k].x + B[k].w <= B[i].x) continue;
		if (B[i].h < B[k].h) continue;
		tmp[cnt++] = B[i];
	}

	if (cnt == 0) return true;
	sort(tmp, tmp + cnt);
	int cur = B[k].x;

	for (int i = 0; i < cnt; i++)
		if (cur < tmp[i].x) return true;
		else cur = max(cur, tmp[i].x + tmp[i].w);

	return cur < B[k].x + B[k].w ;
}

int main() {
	while (scanf("%d", &N) && N) {
		for (int i = 0; i < N; i++) {
			scanf("%d%d%d%d%d", &B[i].x, &B[i].y, &B[i].w, &B[i].d, &B[i].h);
			B[i].id = i + 1;
		}
		sort(B, B + N);

		if (T) puts("");
		printf("For map #%d, the visible buildings are numbered as follows:\n", ++T);

		int flag = 0;
		for (int i = 0; i < N; i++)
			if (judge(i)) {
				if (flag++) printf(" ");
				printf("%d", B[i].id);
			}
		puts("");
	}
	return 0;
}
