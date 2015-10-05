#include <cstdio>
#include <algorithm>
using namespace std;

int A[1010][1550];

struct Section {
	int num, H;
	bool operator < (Section a) const {
		return H > a.H;
	}
};


int solve(int pos) {
	if (A[pos][0] == 0) return 1;
	Section P[1010], S[1010];

	int cnt = 0, cur = 0, H = 1, cnt2 = 0;
	for (int j = 1; cnt <= A[pos][0]; j++) {
		if (A[pos][j]) {
			P[cur++].H = solve(A[pos][j]);
			cnt++;
		}
		else {
			sort(P, P + cur);
			for (int i = 0; i < cur; i++)
				H = max(H, i + P[i].H);
			H -= cur;

			S[cnt2].H = H;
			S[cnt2++].num = cur;
			cur = 0, H = 1;
			if (cnt == A[pos][0]) cnt++;
		}
	}

	sort(S, S + cnt2);
	
	int tmp = 0;
	for (int j = 0; j < cnt2; j++) {
		if (j) tmp += S[j-1].num;
		H = max(H, S[j].H + tmp + S[j].num);
	}
	return H;
}	

int main() {
	int N, K;
	scanf("%d", &N);
	for (int i = 0; i <= N; i++) {
		scanf("%d", &A[i][0]);
		int cnt = 0;
		for (int j = 1; cnt < A[i][0]; j++) {
			scanf("%d", &A[i][j]);
			if (A[i][j]) cnt++;
		}
	}
	printf("%d\n", solve(0));
	return 0;
}
