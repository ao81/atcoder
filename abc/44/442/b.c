#include <stdio.h>

int main(void) {
	int q, vol = 0, play = 0;
	scanf("%d", &q);
	while (q--) {
		int a;
		scanf("%d", &a);
		if (a == 1) {
			vol++;
		} else if (a == 2 && vol >= 1) {
			vol--;
		} else if (a == 3) {
			play = !play;
		}

		if (play && vol >= 3) {
			printf("Yes\n");
		} else {
			printf("No\n");
		}
	}

	return 0;
}