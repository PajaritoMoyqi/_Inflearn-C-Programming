#define _CRT_SECURE_NO_WARNINGS // 코드의 최상단에 해당 코드를 정의해두면 scanf 오류가 나지 않는다. scanf_s(강의에서 사용)보다는 이 방법이 더 나음(컴파일 문제).
#include <stdio.h>

int main(void)
{
  // 정수형 변수에 대한 예제
  int age = 12;
  printf("%d\n", age);
  age = 13;
  printf("%d\n", age);

  // 주석에 대한 예제
  /* 
    여러 줄 주석
  */
  // 한 줄 주석

  // 실수형 변수에 대한 예제
  float f = 46.5;
  printf("%.2f\n", f);
  double d = 4.428;
  printf("%lf\n", d);

  // 상수 사용에 대한 예제
  const int YEAR = 2000;
  printf("I was born in %d.\n", YEAR);
  // YEAR = 2010; 에러

  // printf
  int add = 3 + 7;
  printf("3 + 7 = %d\n", add);
  printf("%d + %d = %d\n", 3, 7, 3 + 7);

  // scanf
  int input;
  printf("Please give me an integer input...");
  scanf("%d", &input);
  printf("input value: %d\n", input);
  
  int one, two, three;
  printf("Give me your 3 favorite integer values...");
  scanf("%d\n%d\n%d", &one, &two, &three);
  printf("You love %d, %d and %d.\n", one, two, three);

  // 문자: 한 글자, 문자열: 한 글자 이상의 여러 글자로 구성됨
  char c = 'A'; // 한 글자는 홑따옴표, 여러 개는 쌍따옴표를 써야 한다.
  // 더 자세히 설명하자면, 한 글자에 쌍따옴표를 쓸 경우 뒤에 \n이 붙게 된다.
  // %s는 null 문자가 나타날 때까지 읽으므로, 한 문자를 쓰더라도 쌍따옴표를 쓰는 것이 좋다.
  printf("%c\n", c);
  char str[256];
  scanf("%s", str, sizeof(str));
  printf("%s\n", str);

  return 0;
}