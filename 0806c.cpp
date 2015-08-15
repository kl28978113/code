#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define pb push_back
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
vector<int> ans[15];
int sumv[15];

bool vis[N];
ll n, m;
ll sum, avg, res;

void init() {
	memset(sumv, 0, sizeof(sumv));
	memset(vis, false, sizeof(vis));
	for(int i = 0; i <= m; i++)
		ans[i].clear();
}

void dfs(int cur) {
	if(cur == m + 1) return;
	ll tmp = avg - sumv[cur]; 

	for(int i = res; i > 0; i--) {
		if(vis[i]) continue;
		vis[i] = true;

		tmp -= i;
		sumv[cur] += i;
		ans[cur].pb(i);

		if(tmp <= i) i = tmp + 1;

		if(sumv[cur] == avg) {
			dfs(cur+1);
		}
	}
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		memset(vis, false, sizeof(vis));
		scanf("%lld%lld", &n, &m);
		init();

		if(n & 1) sum = (n + 1) / 2 * n;
		else sum = n / 2 * (n + 1);

		if(sum % m != 0 ) {
			puts("NO");
			continue;
		}

		avg = sum / m;
		if(avg < n) {
			puts("NO");
			continue;
		}
		puts("YES");

		res = n % (2 * m);

	//	if(res != 0) {
			res += 2 * m; 
	//		res = min(n, res);
	//	}

		//$(A7V3I(B2 * m$(A7](B
		int a, b;
		for(int i = n; i > res; i -= (2 * m)) {
			for(int k = 1; k <= m; k++) {
				a = i - k + 1, b = i - (2 * m) + k;
				ans[k].pb(a), ans[k].pb(b);
				sumv[k] += a; sumv[k] += b;
			}
		}
		dfs(1);
		for(int i = 1; i <= m; i++) {
			int size = ans[i].size();
			printf("%d", size);
			for(int k = 0; k < size; k++)
				printf(" %d",ans[i][k]);
			puts("");
		}
	}
	return 0;
}

