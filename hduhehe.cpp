#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Fuck {
	char sb[200];
	int age;
	bool operator < (Fuck a) const {
		return age > a.age;
	}
} fuck[110];

int main() {
	int T;
	scanf("%d\n", &T);
	while (T--) {
		int n;
		scanf("%d%*c", &n);
		for (int i = 0; i < n; i++) {
			gets(fuck[i].sb);
			int n = strlen(fuck[i].sb);
			fuck[i].age = (fuck[i].sb[n-4]-'0') * 1000 + (fuck[i].sb[n-3]-'0') * 100 + (fuck[i].sb[n-2]-'0') * 10 + (fuck[i].sb[n-1]-'0'); 
			fuck[i].sb[n-5] = 0;
		}
		sort(fuck, fuck + n);
		for (int i = 0; i < n; i++) {
	//		printf("%d ", fuck[i].age);
			puts(fuck[i].sb);
		}
	}
	return 0;
}
