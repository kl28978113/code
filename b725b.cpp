#include <cstdio>
#include <iostream>
#include <string> 
using namespace std;

int main() {
	int T;
	char s[15] = "anniversary";
	string str;
	scanf("%d", &T);
	while (T--) {
		cin >> str;
		for (int i = 1; i < 10; i++)
			for (int j = i + 1; j < 11; j++) {
				char s1[15] = {0}, s2[15] = {0}, s3[15] = {0};
				for (int k = 0; k < i; k++)
					s1[k] = s[k];
				for (int k = i; k < j; k++)
					s2[k-i] = s[k];
				for (int k = j; k < 11; k++)
					s3[k-j] = s[k];
				int pos1, pos2, pos3;
				pos1 = str.find(s1, 0);
				pos2 = str.find(s2, pos1 + i);
				pos3 = str.find(s3, pos2 + j - i);
				if (pos1 != -1  && pos2 != -1 && pos3 != -1) {
				//	printf("%d %d %d\n", pos1, pos2, pos3);
					puts("YES");
					goto flag;
				}
			}
		puts("NO");
flag:;
				 
	 			// 0 1   2  3 4 5 6   7   8  9  10
				 //a  n  n  i v  e  r  s  a  r  y;
	}
	return 0;
}
