#include <stdio.h>

int main(){
    int x;
    printf("Enter number of itirations: ");
    scanf("%d", &x);

    int i;
    for (i = 0; i < x; i++){
        printf("Hello from C <3\n");
    }
    return 0;
}