#include <cstdio>
long long A[100010], ans[100010];
bool left, right;
int n;

bool DFS(int sum, int pos) {
	if (pos == n - 1) {
		if (sum + A[pos] == 0)
			return true;
		return false;
	}

	if (A[pos] == 0)
		if (DFS(sum, pos + 1)) return true;

	if (sum == 1) {
		if (A[pos] > 0)
			return false;
		left = false;
		if (DFS(sum + A[pos], pos + 1)) return true;
		left = true;
	}

	if (sum == -1) {
		if (A[pos] < 0)
			return false;
		right = false;
		if (DFS(sum + A[pos], pos + 1)) return true;
		right = true;
	}

	if (A[pos] == 2) {
		if (right == false)
			return false;
		left = right = false;
		if (DFS(1, pos + 1)) return true;
		left = right = true;

	} else if (A[pos] == 1) {
		left = false;
		if (DFS(1, pos + 1)) return true;
		left = true;
		if (right != false) {
			right = false;
			if (DFS(0, pos + 1)) return true;
			right = true;
		}

	} else if (A[pos] == -2) {
		if (left == false)
			return false;
		left = right = false;
		if (DFS(-1, pos + 1)) return true;
		left = right = true;

	} else if (A[pos] == -1) {
		right = false;
		if (DFS(-1, pos + 1)) return true;
		right = true;
		if (left != false) {
			left = false;
			if (DFS(0, pos + 1)) return true;
			left = true;
		}
	}
	return false;
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		long long tmp = 0;
		for (int i = 0; i < n; i++) {
			scanf("%lld", &A[i]);
			tmp += A[i];
		}
		if (tmp % n != 0) {
			puts("NO");
			continue;
		}

		long long avg = tmp / n;
		for (int i = 0; i < n; i++) {
			if (A[i])
			A[i] -= avg;
		}
		left = right = true;
		DFS(0, 0) ? puts("YES") : puts("NO");
	}
	return 0;
}
