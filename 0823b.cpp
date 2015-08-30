#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100010;
struct hehe {
	int sum;
	int price;
} A[maxn], B[maxn];

bool cmp(hehe a, hehe b) {
	if (a.price == b.price)
		return a.sum > b.sum;
	return a.price > b.price;
}


int main() {
	int n, s, p, q, cntA = 0, cntB = 0;
	char d[10];
	scanf("%d%d", &n ,&s);
	for (int i = 0; i < n; i++) {
		scanf("%s%d%d", d, &p, &q);
		if(d[0] == 'S') {
			if (A[p].sum == 0) cntA++;
			A[p].sum += q;
			A[p].price = p;
		}
		else {
			if (B[p].sum == 0) cntB++;
			B[p].sum += q;
			B[p].price = p;
		}
	}
	sort(A, A + maxn, cmp);
	sort(B, B + maxn, cmp);
	//cntA = min(cntA, s);
	int l = max(cntA - s, 0);
	cntB = min(cntB, s);
	for (int i = l; i < cntA; i++) {
		printf("S %d %d\n", A[i].price, A[i].sum);
	}

	for (int i = 0; i < cntB; i++) {
		printf("B %d %d\n", B[i].price, B[i].sum);
	}

	return 0;
}
