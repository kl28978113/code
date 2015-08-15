#include <cstdio>  
int A[50010];  

int find(int x) {  
	return A[x] == x ? x : A[x] = find(A[x]);  
}  

int main() {  
	int n, q;  
	while (scanf("%d%d", &n, &q) != EOF) {
		for (int i = 0; i <  n + 10; i++)  
			A[i] = i;  

		int X, Y;
		for (int i = 0; i < q; i++) {
			scanf("%d%d", &X, &Y);
			A[find(Y)] = find(X);
		}

		int cnt = 0;
		for (int i = 1; i <= n; i++)
			if (A[i] == i)
				cnt++;
		printf("%d\n", cnt);
	}
	return 0;  
}  
