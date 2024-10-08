> # 🖨 ft_printf

C 언어의 `prinft()` 구현하기

## ✅ Mandatory part

기본적인 서식 지정자를 구현하기

### 구현한 서식 지정자

| 서식 지정자 | 설명                                                     |
| ----------- | -------------------------------------------------------- |
| **`%c`**    | 단일 문자 출력                                           |
| **`%s`**    | 문자열 출력                                              |
| **`%p`**    | `void *` 형식의 포인터를 16진수(`0x` 접두사 포함)로 출력 |
| **`%d`**    | 10진수 부호 있는 정수 출력                               |
| **`%i`**    | 10진수 부호 있는 정수 출력 (`%d`와 동일)                 |
| **`%u`**    | 부호 없는 10진수 정수 출력                               |
| **`%x`**    | 부호 없는 16진수 출력 (소문자)                           |
| **`%X`**    | 부호 없는 16진수 출력 (대문자)                           |
| **`%%`**    | 퍼센트 기호 출력                                         |

<br>

## ✅ Bonus part

서식 지정자를 세밀하게 제어할 수 있도록 **플래그**, **너비**, **정밀도** 구현하기

`printf()` 형식 문자열

```
%[flag][width][.precision][length]서식 지정자
```

### 구현한 flag

| 플래그        | 설명                                                      |
| ------------- | --------------------------------------------------------- |
| **`-`**       | 왼쪽 정렬(기본값: 오른쪽 정렬)                            |
| **`0`**       | 너비가 지정된 경우, 빈자리를 0으로 채움                   |
| **`#`**       | (%o, %x, %X) 각 진법에 맞게 0, 0x, 0X 출력                |
| **`(space)`** | 양수일 경우, 앞에 공백을 추가                             |
| **`+`**       | 양수에도 +를 붙여서 출력, 음수는 기본적으로 -를 붙여 출력 |

### width

- 출력 값이 차지할 최소 자리수를 지정한다.
- 너비가 값보다 크면 빈 공간은 공백이나 0으로 채운다.
- 너비가 값보다 작으면 옵션을 무시한다.

### .precision

- 출력할 값의 자릿수를 제한한다.
- 서식 지정자 앞에 `.`을 찍어서 사용한다.
- 정수에 대한 정밀도
  - 지정된 자릿수가 값보다 크면 자릿수를 맞추기 위해 0으로 채운다.
  - 지정된 자릿수가 값보다 작으면 옵션을 무시한다.
- 문자열에 대한 정밀도
  - 지정된 자릿수가 문자열 길이보다 작으면 잘라서 출력한다.
  - 지정된 자릿수가 문자열 길이보다 크면 옵션을 무시한다.

<br>

## 🎬 실행 예시

`main.c`

```c
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

```

`터미널`

```
make

gcc main.c libftprintf.a -o ft_printf

./ft_printf

=== 기본 서식 지정자 ===
1. 문자 출력: [A]
1. 문자 출력: [A]

2. 문자열 출력: [Hello, World!]
2. 문자열 출력: [Hello, World!]

3. 포인터 주소 출력: [0x7ffee44de5b8]
3. 포인터 주소 출력: [0x7ffee44de5b8]

4. 부호 있는 10진수: [42]
4. 부호 있는 10진수: [42]

5. 부호 없는 10진수: [42]
5. 부호 없는 10진수: [42]

6. 소문자 16진수: [2a]
6. 소문자 16진수: [2a]

7. 대문자 16진수: [2A]
7. 대문자 16진수: [2A]

8. 퍼센트 기호: [%]
8. 퍼센트 기호: [%]

=== 플래그 ===
9. 왼쪽 정렬: [42        ]
9. 왼쪽 정렬: [42        ]

10. 0으로 채움: [0000000042]
10. 0으로 채움: [0000000042]

11. 공백 플래그: [ 42]
11. 공백 플래그: [ 42]

12. 플러스 플래그: [+42]
12. 플러스 플래그: [+42]

13. 해시 플래그: [0x2a]
13. 해시 플래그: [0x2a]

14. 음수 (공백 플래그): [-42]
14. 음수 (공백 플래그): [-42]

15. 음수 (플러스 플래그): [-42]
15. 음수 (플러스 플래그): [-42]

=== 너비 (Width) ===
16. 너비: [   42]
16. 너비: [   42]

17. 음수 너비: [  -42]
17. 음수 너비: [  -42]

18. 0으로 채운 너비: [00042]
18. 0으로 채운 너비: [00042]

19. 음수 0으로 채운 너비: [-0042]
19. 음수 0으로 채운 너비: [-0042]

=== 정밀도 (Precision) ===
20. 정밀도: [00042]
20. 정밀도: [00042]

21. 음수 정밀도: [-00042]
21. 음수 정밀도: [-00042]

22. 문자열 정밀도: [Hello]
22. 문자열 정밀도: [Hello]

=== 복합 테스트 (Flags + Width + Precision) ===
23. 플래그, 너비, 정밀도: [    +00042]
23. 플래그, 너비, 정밀도: [    +00042]

24. 왼쪽 정렬 및 정밀도: [00042     ]
24. 왼쪽 정렬 및 정밀도: [00042     ]

25. 0으로 채운 너비 및 정밀도: [     00042]
25. 0으로 채운 너비 및 정밀도: [     00042]
```

<br>

## ✏️ Review

- 가변 인자 처리와 문자열 파싱을 배울 수 있었습니다.
- 코드의 재사용성과 확장성의 중요성을 알게 되었습니다.
- 다양한 테스트 케이스를 직접 작성하며, 출력 결과가 기존의 printf() 함수와 동일하게 동작하는 지 확인할 수 있었습니다. 이를 통해 디버깅 및 테스트 주도 개발의 중요성을 알게 되었습니다.
