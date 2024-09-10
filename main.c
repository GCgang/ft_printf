#include <stdio.h>
#include "bonus/ft_printf_bonus.h"

int main(void)
{
    int num = 42;
    int neg_num = -42;
    char c = 'A';
    char *str = "Hello, World!";
    void *ptr = &num;

    // === 기본 서식 지정자 테스트 ===
    printf("=== 기본 서식 지정자 ===\n");

    printf("1. 문자 출력: [%c]\n", c);
    ft_printf("1. 문자 출력: [%c]\n", c);
    printf("\n");

    printf("2. 문자열 출력: [%s]\n", str);
    ft_printf("2. 문자열 출력: [%s]\n", str);
    printf("\n");

    printf("3. 포인터 주소 출력: [%p]\n", ptr);
    ft_printf("3. 포인터 주소 출력: [%p]\n", ptr);
    printf("\n");

    printf("4. 부호 있는 10진수: [%d]\n", num);
    ft_printf("4. 부호 있는 10진수: [%d]\n", num);
    printf("\n");

    printf("5. 부호 없는 10진수: [%u]\n", num);
    ft_printf("5. 부호 없는 10진수: [%u]\n", num);
    printf("\n");

    printf("6. 소문자 16진수: [%x]\n", num);
    ft_printf("6. 소문자 16진수: [%x]\n", num);
    printf("\n");

    printf("7. 대문자 16진수: [%X]\n", num);
    ft_printf("7. 대문자 16진수: [%X]\n", num);
    printf("\n");

    printf("8. 퍼센트 기호: [%%]\n");
    ft_printf("8. 퍼센트 기호: [%%]\n");
    printf("\n");

    // === 플래그 테스트 ===
    printf("=== 플래그 ===\n");

    printf("9. 왼쪽 정렬: [%-10d]\n", num);
    ft_printf("9. 왼쪽 정렬: [%-10d]\n", num);
    printf("\n");

    printf("10. 0으로 채움: [%010d]\n", num);
    ft_printf("10. 0으로 채움: [%010d]\n", num);
    printf("\n");

    printf("11. 공백 플래그: [% d]\n", num);
    ft_printf("11. 공백 플래그: [% d]\n", num);
    printf("\n");

    printf("12. 플러스 플래그: [%+d]\n", num);
    ft_printf("12. 플러스 플래그: [%+d]\n", num);
    printf("\n");

    printf("13. 해시 플래그: [%#x]\n", num);
    ft_printf("13. 해시 플래그: [%#x]\n", num);
    printf("\n");

    printf("14. 음수 (공백 플래그): [% d]\n", neg_num);
    ft_printf("14. 음수 (공백 플래그): [% d]\n", neg_num);
    printf("\n");

    printf("15. 음수 (플러스 플래그): [%+d]\n", neg_num);
    ft_printf("15. 음수 (플러스 플래그): [%+d]\n", neg_num);
    printf("\n");

    // === 너비 (Width) 테스트 ===
    printf("=== 너비 (Width) ===\n");

    printf("16. 너비: [%5d]\n", num);
    ft_printf("16. 너비: [%5d]\n", num);
    printf("\n");

    printf("17. 음수 너비: [%5d]\n", neg_num);
    ft_printf("17. 음수 너비: [%5d]\n", neg_num);
    printf("\n");

    printf("18. 0으로 채운 너비: [%05d]\n", num);
    ft_printf("18. 0으로 채운 너비: [%05d]\n", num);
    printf("\n");

    printf("19. 음수 0으로 채운 너비: [%05d]\n", neg_num);
    ft_printf("19. 음수 0으로 채운 너비: [%05d]\n", neg_num);
    printf("\n");

    // === 정밀도 (Precision) 테스트 ===
    printf("=== 정밀도 (Precision) ===\n");

    printf("20. 정밀도: [%.5d]\n", num);
    ft_printf("20. 정밀도: [%.5d]\n", num);
    printf("\n");

    printf("21. 음수 정밀도: [%.5d]\n", neg_num);
    ft_printf("21. 음수 정밀도: [%.5d]\n", neg_num);
    printf("\n");

    printf("22. 문자열 정밀도: [%.5s]\n", str);
    ft_printf("22. 문자열 정밀도: [%.5s]\n", str);
    printf("\n");

    // === 복합 테스트 (Flags + Width + Precision) ===
    printf("=== 복합 테스트 (Flags + Width + Precision) ===\n");

    printf("23. 플래그, 너비, 정밀도: [%+010.5d]\n", num);
    ft_printf("23. 플래그, 너비, 정밀도: [%+010.5d]\n", num);
    printf("\n");

    printf("24. 왼쪽 정렬 및 정밀도: [%-10.5d]\n", num);
    ft_printf("24. 왼쪽 정렬 및 정밀도: [%-10.5d]\n", num);
    printf("\n");

    printf("25. 0으로 채운 너비 및 정밀도: [%010.5d]\n", num);
    ft_printf("25. 0으로 채운 너비 및 정밀도: [%010.5d]\n", num);
    printf("\n");

    return 0;
}
