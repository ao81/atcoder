#include <stdio.h>
#include <string.h>

int main(void) {
    char str[13];
    scanf("%11s", str);

    int len = strlen(str);

    str[len] = 's';
    str[len + 1] = '\0';

    printf("%s\n", str);
    return 0;
}
