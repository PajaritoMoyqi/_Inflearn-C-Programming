#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
  int floor;
  printf("How many floor do you want to make?\n");
  scanf("%d", &floor);

  for (int i = 0; i < floor; i++)
  {
    for (int k = 1; k < floor - i; k++)
    {
      printf(" ");
    }
    for (int j = 0; j < 2*i + 1; j++)
    {
      printf("*");
    }
    printf("\n");
  }
  
  return 0;
}