#include <cstdio>
#include <cmath>

const double PI = acos(-1);

int main() {
	printf("1, 1 = %lf\n -1, 1 = %lf\n -1, -1 = %lf\n 1, -1 = %lfd\n", atan2(1,1) / PI * 180, 
		atan2(1, -1)/ PI * 180, atan2(-1, -1)/ PI * 180, atan2(-1, 1)/ PI * 180);
	return 0;
}
