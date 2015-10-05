#include <cstdio>
#include <cmath>

int main() {
	int n; 
	while (scanf("%d", &n) != EOF) {
		bool flag = true;
		for (int i = 0; i < n; i++) {
			int x;
			scanf("%d", &x);  
			if (!flag)
				continue;
			int y = (int)sqrt(1.0 * x);
			//printf("(%d %d)", y, x);
			if (y * y != x) {
				flag = false;
			}
		}
		if (!flag)
			puts("No");
		else
			puts("Yes");
	}
	return 0;
}
