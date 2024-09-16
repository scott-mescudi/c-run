#include <stdio.h>

void print_pattern(int n) {
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

int main() {
    int n = 20;

    print_pattern(n);
    return 0;

}