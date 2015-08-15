#include <cstdio> 
#include <algorithm>
using namespace std;

struct Pos{
	int key, ID;
	bool operator < (Pos a) const {
		if (key != a.key) return key > a.key;
		return ID < a.ID;
	}
} F[150010];

int main() {
	int n, p;
	char A[150010], B[150010];
	while (scanf("%d%d", &n, &p) != EOF && n + p) {
		scanf("%s%s", A + 1, B + 1);
		int sum = 0;
		for (int i = 1; i <= n; i++) {
			sum += (A[i] != B[i]);
			F[i].key = 100 * sum - i * p; 
			F[i].ID = i;
		}
		sort(F + 1, F + 1 + n);

		int MAX = 0, MIN = F[1].ID;
		for (int i = 1; i <= n; i++) {
			MAX = max(MAX, F[i].ID - MIN);
			MIN = min(MIN, F[i].ID);
		}

		if (MAX > 0) printf("%d\n", MAX);
		else puts("No solution.");
	}
	return 0;
}
