#include <cstdio>

int main() {
	int T;
	scanf("%d%*c", &T);
	while (T--) {
		int len;
		scanf("%d%*c", &len);
		char pre = getchar(), cur;
		int cnt = 1, num[3] = {0};
		bool flag = false;

		for (int i = 1; i <= len; i++) {
			cur = getchar();
			if (cur == pre) {
				cnt++;
			} else {
				num[0] = num[1];
				num[1] = num[2];
				num[2] = cnt;
				cnt = 1;

				if (num[0] >= num[1] && num[1] <= num[2] && num[1])
					flag = true;

				if (cur - pre != 1)
					num[0] = num[1] = num[2]= 0;
			} 

			pre = cur;
		}
		flag ? puts("YES") : puts("NO");
	}
	return 0;
}
