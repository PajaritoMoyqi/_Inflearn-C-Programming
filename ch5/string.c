#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
  // character
  char c = 'A';
  printf("%c\n", c);

  // string
  char str[6] = "coding"; // [c] [o] [d] [i] [n] [g]
  printf("%s\n", str); // null 문자가 존재할 공간이 없어서 이상한 게 출력된다.
  char str2[7] = "coding"; // [c] [o] [d] [i] [n] [g] [\0] <- NULL
  printf("%s\n", str2);

  char str3[] = "coding";
  printf("%s\n", str3);
  printf("%d\n", sizeof(str3));

  for (int i = 0; i < sizeof(str3); i++)
  {
    printf("%c\n", str3[i]);
  }

  char kor[] = "인프런";
  printf("%s\n", kor);
  printf("%d\n", sizeof(kor)); // 한 글자당 3의 공간을 차지한다. UTF-8을 사용했기 때문!
  /*
    >>> '가'.encode('utf-8')
    b'\xea\xb0\x80'
    >>> '가'.encode('euc-kr')
    b'\xb0\xa1'
  */

  char c_array[7] = { 'c', 'o', 'd', 'i', 'n', 'g', '\0' };
  printf("%s\n", c_array);
  char c_array2[6] = { 'c', 'o', 'd', 'i', 'n', 'g' };
  printf("%s\n", c_array2); // \0가 없어서 뒤에 이상한 게 붙어서 나온다!

  char c_array3[10] = { 'c', 'o', 'd', 'e' };
  for (int i = 0; i < sizeof(c_array3); i++)
  {
    printf("%c\n", c_array3[i]);
    printf("%d\n", c_array3[i]); // 아스키 코드
  }

  // 아스키 코드
  printf("%c\n", 'a');
  printf("%d\n", 'a');
  printf("%c\n", 'b');
  printf("%d\n", 'b');
  printf("%c\n", 'A');
  printf("%d\n", 'A');
  printf("%c\n", '\0');
  printf("%d\n", '\0');
  printf("%c\n", '0');
  printf("%d\n", '0');

  return 0;
}