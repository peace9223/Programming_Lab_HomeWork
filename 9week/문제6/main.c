#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int sum(int n);
int factorial(int n);
int fibo(int n);
void binary(int n);
void octal(int n);
void hexa(int n);

int main(void) {
    int i;

    // sum(10)
    printf("sum(10) = %d\n", sum(10));

    // factorial(10)
    printf("factorial(10) = %d\n", factorial(10));

    // fibonacci 0 ~ 10
    printf("fibonacci = ");
    for (i = 0; i <= 10; i++)
        printf("%d ", fibo(i));
    printf("\n");

    // binary(12345)
    printf("binary(12345) = ");
    binary(12345);
    printf("\n");

    // octal(12345)
    printf("octal(12345) = ");
    octal(12345);
    printf("\n");

    // hexa(12345)
    printf("hexa(12345) = ");
    hexa(12345);
    printf("\n");

    return 0;
}

// 1 ~ n 까지의 합
int sum(int n) {
    if (n <= 1)
        return n;
    else
        return n + sum(n - 1);
}

// n!
int factorial(int n) {
    if (n <= 1)
        return 1;
    else
        return n * factorial(n - 1);
}

// 피보나치
int fibo(int n) {
    if (n <= 1)
        return n;
    else
        return fibo(n - 1) + fibo(n - 2);
}

// 10진수 → 2진수
void binary(int n) {
    if (n < 2)
        printf("%d", n);
    else {
        binary(n / 2);
        printf("%d", n % 2);
    }
}

// 10진수 → 8진수
void octal(int n) {
    if (n < 8)
        printf("%d", n);
    else {
        octal(n / 8);
        printf("%d", n % 8);
    }
}

// 10진수 → 16진수
void hexa(int n) {
    if (n < 16) {
        if (n < 10)
            printf("%d", n);             // 0~9는 숫자 그대로
        else
            printf("%c", 'A' + (n - 10)); // 10~15는 A~F
    }
    else {
        hexa(n / 16);
        int r = n % 16;
        if (r < 10)
            printf("%d", r);
        else
            printf("%c", 'A' + (r - 10));
    }
}
// 7-7 7-8 문제를 참고해서 7-9문제를 풀것 출력방식은 7-7의 방식을 따를것
// acm1 문제 설명대로하지 말고 acm1 슬라이드13에서 나온 방식처럼 문제를 가장 작은수부터 순서대로 풀것
// acm2의 과제는 결과보단 과정을 적는것을 하면 된다. 동영상 참고
// unkonwn은 비주얼스튜디오에서는 잘 실행이 안됌 즉 로직 자체는 입력의 역순으로 출력