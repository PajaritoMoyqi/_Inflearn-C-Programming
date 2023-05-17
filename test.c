#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void p(int num)
{
  printf("num은 %d입니다.\n",num);
}

int main(void)
{
  int num = 2;
  p(num);

  return 0;
}
