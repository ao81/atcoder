#include <stdio.h>

int main(void) {
	int n, k, i, x = 0;
	scanf("%d %d", &n, &k);
	for (i = 0;; ++i) {
		x += n + i;
		if (x >= k) break;
	}
	printf("%d\n", i);
	return 0;
}