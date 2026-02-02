#include <stdio.h>
#include <string.h>

int main(void) {
	char str[11];
	int cnt = 0;
	scanf("%s", str);
	int len = strlen(str);
	for(int i = 0; i < len; i++) {
		if (str[i] == 'i' || str[i] == 'j') {
			cnt++;
		}
	}
	printf("%d\n", cnt);
	return 0;
}