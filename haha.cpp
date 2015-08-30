#include <cctype>
#include <cstdio>
#include <algorithm>
using namespace std;

const long long MOD = 3221225473;
const int MAXN = 3000010;
int A[MAXN], rec[MAXN]; 

namespace IO {
    const static int maxn = 200 << 20;
    static char buf[maxn], *pbuf = buf, *End;
    void init() {
        int c = fread(buf, 1, maxn, stdin);
        End = buf + c;
    }
    int &readint() {
        static int ans;
        ans = 0;
        while (pbuf != End && !isdigit(*pbuf)) pbuf ++;
        while (pbuf != End && isdigit(*pbuf)) {
            ans = ans * 10 + *pbuf - '0';
            pbuf ++;
        }
        return ans;
    }
}

int main() {
	IO::init();
	int T;
	T = IO::readint();
	while (T--) {
		int n;
		n = IO::readint();
		for (int i = 1; i <= n; i++)
			A[i] = IO::readint();

		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			int pos = i, tmp = 0, next;
			while (A[pos]) {
				next = A[pos];
				A[pos] = 0;
				pos = next;
				tmp++;
			}
			if (tmp != 0)
				rec[cnt++] = tmp;
		}

		long long ans = 1;
		for (int i = 0; i < cnt; i++) {
			int tmp = rec[i];
			for (int j = 2; j * j <= tmp; j++) {
				int num = 0;
				while (tmp % j == 0) {
					tmp /= j;
					num++;
				}
				A[j] = max(A[j], num);
			}
			if (tmp > 1) A[tmp] = max(1, A[tmp]);
		}

		for (int i = 2; i <= n; i++)
			while (A[i]--) ans = (ans * i) % MOD;

		printf("%lld\n", ans);
	}
	return 0;
}
