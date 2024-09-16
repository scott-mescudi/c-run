#include <stdio.h>


float add(float arg1, float arg2){
    return arg1 + arg2;
}

float subtract(float arg1, float arg2){
    return arg1 - arg2;
}

float multiply(float arg1, float arg2){
    return arg1 * arg2;
}

float divide(float arg1, float arg2){
    if (arg1 == 0 || arg2 == 0){
        printf("Error: Division by zero is not allowed.\n");
        return 0;
    }

    return arg1 / arg2;
}

int main(){
    char arg1;
    printf("Enter selection: ");
    scanf("%c", &arg1);

    float num1, num2;
    printf("Enter two numbers: ");
    scanf("%f %f", &num1, &num2);

    switch (arg1)
    {
    case 'a':
        printf("Addition: %.2f\n", add(num1, num2));
        break;
    case 's':
        printf("Subtraction: %.2f\n", subtract(num1, num2));
        break;
    case 'm':
        printf("Subtraction: %.2f\n", multiply(num1, num2));
        break;
    case 'd':
        printf("Subtraction: %.2f\n", divide(num1, num2));
        break;
    default:
        printf("Error: Invalid selection.\n");
        break;
    }

    return 0;
}