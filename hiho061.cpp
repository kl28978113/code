#include <cstdio> 
int n, m, a[50010];
char s[50010], c[10];
int l, r, k, op, cur;
int tmp[50010];

int main() {
	scanf("%d%d%s", &n, &m, s);
	for (int i = 0; i < n; i++)
		a[i] = s[i] - 'A';

	//for (int i = 0; i < m; i++) {
	while(m--) {
		scanf("%*s%d", &op);
		if (op == 1) {
			scanf("%d%d %s", &l, &r, c);
			l = (l + cur) % n;
			r = (r + cur) % n;
			// l = (l - 1 + cur) % n;
			// r = (r - 1 + cur) % n;
			//c[0] -= 'A';
			k = c[0] - 'A';
			

			if (l <= r) {
				for (int i = l-1; i < r; i++)
					a[i] = k;
			} else {
				for (int i = l-1; i < n; i++)
					a[i] = k;
				for (int i = 0; i < r; i++)
					a[i] = k;
			}

		} else if (op == 2) {
			scanf("%d%d%d", &l, &r, &k);
			l = (l + cur) % n;
			r = (r + cur) % n;


			// l = (l - 1 + cur) % n;
			// r = (r - 1 + cur) % n;

			if (l <= r) {
				for (int i = l-1; i < r; i++)
					a[i] += k;
			} else {
				for (int i = l-1; i < n; i++)
					a[i] += k;
				for (int i = 0; i < r; i++)
					a[i] += k;
			}
		} else if (op == 3) {
			scanf("%d", &k);
			cur = (cur + k) % n;
		} else {
			scanf("%d%d", &l, &r);
			l = (l + cur) % n;
			r = (r + cur) % n;
			// l = (l - 1 + cur) % n;
			// r = (r - 1 + cur) % n;
			if (r < l)
				r += n;
			for (int i = l-1, cnt = 1; i < r; i++, cnt++) {
				if (i < n)
					a[i] += cnt;
				else
					a[i-n] += cnt;

			}

			// if (l < r) {
				// for (int i = l-1; i < r; i++)
					// a[i] += ++cnt;
			// } else {
				// for (int i = l-1; i < n; i++)
					// a[i] += ++cnt;
				// for (int i = 0; i < r; i++)
					// a[i] += ++cnt;
			// }
		}
	}
	for (int i = 0; i < cur; i++)
		tmp[i] = a[i];
	for (int i = cur; i < n; i++)
		a[i-cur] = a[i];
	for (int i = 0; i < cur; i++)
		a[n-cur+i] = tmp[i];
	for (int i = 0; i < n; i++)
		printf("%c", a[i]%26 + 65);
	puts("");

	// for (int i = 0; i < n; i++)
		// printf("%c", (a[(i + cur) % n] % 26) + 'a');
	// puts("");
	return 0;
}
