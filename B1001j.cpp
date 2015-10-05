#include <map>
#include <cstdio>
using namespace std;

map<int, int> Map, Mapx, Mapy;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int DFS(int x, int y, int d) {
	if (M[x][y] == 1) {
		int d = (d + 1) % 4;
		DFS(x + dx[d], y + dy[d], d)
	}

	if (d == 0 || d == 2) {
		if (Mapy[y] == 0)
			return 
		else
			DFS(x + dx[d], y + dy[d], d)

	} else if (d == 1 || d == 3) {
		if (Mapx[x] == 0)
			return;
		else
			DFS(x + dx[d], y + dy[d], d)
	}
}

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		int A[1010][2];
		for (int i = 0; i < n; i++) {
			scanf("%d", &x[i], &y[i]);
			A[i][0] = x[i];
			A[i][1] = y[i];
		}
		sort(x, x + n);
		sort(y, y + n);

		Mapx.clear();
		for (int i = 0; i < n; i++) {
			if (!Mapx[i]) {
				if (i == 0 || x[i] >= x[i-1] + 1)
					cnt++;
				Mapx[i] = cnt++;
			}
		}

		Mapy.clear();
		for (int i = 0; i < n; i++) {
			if (!Mapy[i]) {
				if (i == 0 || y[i] >= y[i-1] + 1)
					cnt++;
				Mapy[i] = cnt++;
			}
		}

		for (int i = 0; i < n; i++) {
			M[mapx[A[i][0]]][mapy[A[i][1]]] = 1;
		}

		DFS();
		return 0;
	}
